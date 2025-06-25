load("@ewdk_cc_toolchains//:resource_toolchain.bzl", "resource_script")
load("@ewdk_cc_toolchains//:wpp_toolchain.bzl", "wpp_trace")
load("@ewdk_cc_toolchains//:ewdk_command.bzl", "ewdk_command")

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
    name = "sys-dll",
    srcs = [":sys_cpps"] +
           select({
               "//:is_windows_x86": ["foo_x86.asm"],
               "//:is_windows_x64": ["foo_x64.asm"],
               "//:is_windows_arm64": ["foo_a64.asm"],
               "//conditions:default": [],
           }),
    features = [
        "cpp20",
        "wdm",
        "subsystem_native",
        "target_win10",
        "stdcall",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
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

ewdk_command(
    name = "sys",
    srcs = [":sys-dll"],
    outs = ["sys.sys"],
    cmd = "copy /y \"$(locations :sys-dll)\" \"$(locations :sys.sys)\" && SignTool.exe sign /ph /fd sha256 /n WDKTestCert \"$(locations :sys.sys)\"",
    tags = ["manual"],
)
