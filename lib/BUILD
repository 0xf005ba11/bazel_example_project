cc_library(
    name = "lib",
    srcs = [
        "lib.cpp",
        "lib.h",
    ],
    hdrs = ["lib.h"],
    features = [
        "msvc_level4_warnings",
        "treat_warnings_as_errors",
    ],
    visibility = ["//visibility:public"],
    alwayslink = True,  # on linux this will effectively cause -whole-archive
)
