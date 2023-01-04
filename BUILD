platform(
    name = "windows_x86",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_32",
    ],
)

platform(
    name = "windows_x64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)

platform(
    name = "windows_arm",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:arm",
    ],
)

platform(
    name = "windows_arm64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:arm64",
    ],
)

platform(
    name = "linux_x64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
)

# select() doesn't support platform()
config_setting(
    name = "is_windows_x86",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_32",
    ],
)

config_setting(
    name = "is_windows_x64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64",
    ],
)

config_setting(
    name = "is_windows_arm",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:arm",
    ],
)

config_setting(
    name = "is_windows_arm64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:arm64",
    ],
)

config_setting(
    name = "is_linux_x64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
)