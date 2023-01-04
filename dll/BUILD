cc_library(
    name = "dll_impl",
    srcs = [
        "dll.cpp",
        "dll.h",
    ],
    hdrs = ["dll.h"], # public interface headers
    features = [
        "cpp20",
        "subsystem_windows",
        "static_link_msvcrt_no_debug",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
    ],
    deps = ["@//lib:lib"],
)

cc_shared_library(
    name = "dll",
    additional_linker_inputs = select({
        "@platforms//os:linux": ["@//dll:dll.lds"], # limit exports similar to windows def file
        "//conditions:default": [],
    }),
    roots = [":dll_impl"],
    static_deps = ["@//lib:lib"],
    user_link_flags = select({
        "@platforms//os:linux": [ "-Wl,--version-script,$(location @//dll:dll.lds)", ],
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
    ],
    deps = [
        ":dll_impl",
        "@gtest//:gtest_main",
    ],
)
