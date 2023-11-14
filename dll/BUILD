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
    ],
    linkopts = select({
        "@platforms//os:windows": ["/DEFAULTLIB:advapi32.lib"],
        "//conditions:default": [],
    }),
    deps = [
        ":dll_wpp",
        "@//lib:lib",
    ],
)

resource_script(
    name = "dll_rc",
    rcfile = "dll.rc",
    tags = ["manual"],
)

# Note: cc_shared_library doesn't seem to properly pass features through on older bazel. This means
#       dynamic_link_msvcrt_no_debug is likely to be used by default due to the CcCommon.java issue.
#       Since cc_shared_library doesn't specify any features itself, to avoid linker warnings, just
#       use dynamic_link_msvcrt_no_debug in the input libraries.
#
#       If you must have static linking, specify static_link_msvcrt_* appropriately in the input
#       libraries, and specify the following in user_link_flags:
#              /NODEFAULTLIB:msvcrt.lib
#              /DEFAULTLIB:libcmt[d].lib

cc_shared_library(
    name = "dll",
    additional_linker_inputs = select({
        "@platforms//os:linux": ["@//dll:dll.lds"],  # limit exports similar to windows def file
        "//conditions:default": [],
    }),
    roots = [":dll_impl"] +
            select({
                "@platforms//os:windows": [":dll_rc"],
                "//conditions:default": [],
            }),
    static_deps = ["@//lib:lib"],
    user_link_flags = select({
        "@platforms//os:linux": ["-Wl,--version-script,$(location @//dll:dll.lds)"],
        "@platforms//os:windows": [
            "/NODEFAULTLIB:msvcrt.lib",
            "/DEFAULTLIB:libcmt.lib",
        ],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    win_def_file = "dll.def",
)

# Note: cc_binary can't be used as a dynamic_dep
#cc_binary(
#    name = "dll",
#    srcs = [],
#    features = [
#        "cpp20",
#        "subsystem_windows",
#        "static_link_msvcrt_no_debug",
#        "msvc_level4_warnings",
#        "treat_warnings_as_errors",
#        "buffer_security_checks",
#        "sdl_security_checks",
#        "cfg_security_checks",
#    ],
#    linkshared = True,
#    target_compatible_with = ["@platforms//os:windows"],
#    deps = [
#        ":dll_impl",
#        ":dll_rc",
#    ],
#)

cc_test(
    name = "dll_test",
    size = "small",
    srcs = glob(["test/*.cpp"]) + ["dll.h"],
    dynamic_deps = [":dll"],
    features = [
        "cpp20",
        "strict_warnings",
        "treat_warnings_as_errors",
        "msvc_no_minmax",
        "subsystem_console",
        "dynamic_link_msvcrt_no_debug",
        "msvc_profile",
    ],
    deps = [
        "@gtest//:gtest_main",
    ],
)
