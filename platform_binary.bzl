# Defines a transition that sets the "--platforms" command line option
def _platform_transition_impl(settings, attr):
    _ignore = (settings, attr)
    return {
        "//command_line_option:platforms": attr.platform,
    }

_platform_transition = transition(
    implementation = _platform_transition_impl,
    inputs = [],
    outputs = ["//command_line_option:platforms"],
)

# This is a wrapping rule that accepts a cc_binary and applies --platforms=<platform>
# so the cc_binary will be built for the specified platform.
def _impl(ctx):
    return [DefaultInfo(files = depset(ctx.files.binary))]

_built_platform_binary = rule(
    implementation = _impl,
    attrs = {
        "binary": attr.label(cfg = _platform_transition),
        "_allowlist_function_transition": attr.label(
            default = "@bazel_tools//tools/allowlists/function_transition_allowlist",
        ),
        "platform": attr.string(mandatory = True),
    },
)

# A macro that ties the output of _built_platform_binary to a genrule so the cc_binary
# output can be made executable in the eyes of bazel. bazel requires a file copy to
# achieve this or it will complain executable output must be created within the same
# rule.
# Possible improvements: This only copies the exe file. It could probably also handle
#                        the pdb file.
def platform_binary(name, binary, platform, **kwargs):
    impl_name = name + "_impl_"
    exe_name = name + ".exe"

    _built_platform_binary(
        name = impl_name,
        binary = binary,
        platform = platform,
        **kwargs
    )
    # A copy must be made to allow the output to be executable within the build system
    # This means something like "bazel run" can execute this target.
    native.genrule(
        name = name,
        srcs = [":" + impl_name],
        outs = [exe_name],
        executable = True,
        cmd_bat = "copy /y \"$(locations :{})\" \"$(locations :{})\"".format(impl_name, exe_name)
    )
