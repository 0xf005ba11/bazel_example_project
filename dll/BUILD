load("@bazel_ewdk_cc//:resource_toolchain.bzl", "resource_script")
load("@bazel_ewdk_cc//:wpp_toolchain.bzl", "wpp_trace")

filegroup(
    name = "dll_cpps",
    srcs = glob(["*.cpp"]),
)

wpp_trace(
    name = "dll_wpp",
    srcs = [":dll_cpps"],
    cfghdr = "@//trace:tracing",
    dll = True,
    tags = ["manual"],
)

cc_library(
    name = "dll_impl",
    srcs = [
        "dll.h",
        ":dll_cpps",
    ],
    hdrs = ["dll.h"],  # public interface headers
    features = [
        "cpp20",
        "subsystem_windows",
        "static_link_msvcrt_no_debug",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
        "no_default_cpp_unwinding",
    ],
    linkopts = select({
        "@platforms//os:windows": ["/DEFAULTLIB:advapi32.lib"],
        "//conditions:default": [],
    }),
    deps = [
        ":dll_wpp",
        "@//lib:lib",
    ],
    alwayslink = True,
)

resource_script(
    name = "dll_rc",
    rcfile = "dll.rc",
    tags = ["manual"],
)

cc_binary(
    name = "dll",
    srcs = [],
    features = [
        "cpp20",
        "subsystem_windows",
        "static_link_msvcrt_no_debug",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
        "buffer_security_checks",
        "sdl_security_checks",
        "cfg_security_checks",
    ],
    linkshared = True,
    target_compatible_with = ["@platforms//os:windows"],
    deps = [
        ":dll_impl",
        ":dll_rc",
    ],
)

cc_test(
    name = "dll_test",
    size = "small",
    srcs = glob(["test/*.cpp"]),
    features = [
        "cpp20",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
        "msvc_no_minmax",
        "subsystem_console",
        "msvc_profile",
    ],
    deps = [
        "dll_impl",
        "@gtest//:gtest_main",
    ],
)
