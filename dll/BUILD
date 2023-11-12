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
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    win_def_file = "dll.def",
)

cc_test(
    name = "dll_test",
    size = "small",
    srcs = glob(["test/*.cpp"]),
    dynamic_deps = [":dll"],
    features = [
        "cpp20",
        "strict_warnings",
        "treat_warnings_as_errors",
        "msvc_no_minmax",
        "subsystem_console",
        "static_link_msvcrt_no_debug",
        "msvc_profile",
    ],
    deps = [
        ":dll_impl",
        "@gtest//:gtest_main",
    ],
)
