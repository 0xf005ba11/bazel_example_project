load("@bazel_ewdk_cc//:resource_toolchain.bzl", "resource_script")
load("@bazel_ewdk_cc//:wpp_toolchain.bzl", "wpp_trace")

filegroup(
    name = "resource_hdrs",
    srcs = ["resources.h"],
)

resource_script(
    name = "sys_rc",
    rcfile = "sys.rc",
    tags = ["manual"],  # don't build on non-windows
    deps = [":resource_hdrs"],
)

filegroup(
    name = "sys_cpps",
    srcs = glob(["*.cpp"]),
)

wpp_trace(
    name = "sys_wpp",
    srcs = [":sys_cpps"],
    cfghdr = "@//trace:tracing",
    kernel = True,
    tags = ["manual"],
)

cc_binary(
    name = "sys",
    srcs = [":sys_cpps"] +
           select({
               "//:is_windows_x86": ["foo_x86.asm"],
               "//:is_windows_x64": ["foo_x64.asm"],
               "//conditions:default": [],
           }),
    features = [
        "cpp20",
        "wdm",
        "subsystem_native",
        "target_win10",
        "stdcall",
        "strict_warnings",
        "treat_warnings_as_errors",
        "msvc_no_minmax",
        "buffer_security_checks",
        "sdl_security_checks",
        "cfg_security_checks",
        "spectre_load_cf",
        "default_includes_cmdline",
    ],
    linkshared = True,
    target_compatible_with = ["@platforms//os:windows"],
    deps = [
        ":sys_rc",
        ":sys_wpp",
    ],
)
