windows_features = [
    "cpp20",
    "subsystem_console",
    "msvc_level4_warnings",
    "static_link_msvcrt",
    "win32_lean_and_mean",
    "buffer_security_checks",
    "sdl_security_checks",
]

linux_features = []

cc_binary(
    name = "exe",
    srcs = ["exe.cpp"],
    features = [
        "treat_warnings_as_errors",
        "cdecl",
    ] + windows_features + linux_features,
)
