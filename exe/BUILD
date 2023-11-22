load("//:platform_binary.bzl", "platform_binary")

windows_features = [
    "cpp20",
    "subsystem_console",
    "msvc_level4_warnings",
    "static_link_msvcrt_no_debug",
    "win32_lean_and_mean",
    "buffer_security_checks",
    "sdl_security_checks",
]

# a binary that will always build for windows x64 regardless of requested platform.
# target_compatible_with makes sure this is skipped for all other platforms, and
# then platform_binary transitions to windows_x64 to build the exe-impl
cc_binary(
    name = "exe-impl",
    srcs = ["exe.cpp"],
    features = [
        "treat_warnings_as_errors",
        "cdecl",
    ] + windows_features,
    target_compatible_with = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)

platform_binary(
    name = "exe",
    binary = "exe-impl",
    platform = "//:windows_x64",
)
