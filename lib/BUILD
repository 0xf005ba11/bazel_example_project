cc_library(
    name = "lib",
    srcs = [
        "lib.cpp",
        "lib.h",
    ],
    hdrs = ["lib.h"],
    features = [
        "cpp20",
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
        "static_link_msvcrt",
    ],
    visibility = ["//visibility:public"],
    alwayslink = True,  # on linux this will effectively cause -whole-archive
)
