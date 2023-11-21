workspace(name = "bazel_example_project")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "bazel_ewdk_cc",
    commit = "abdeeac936f2b9590154aac59eeecfdb997fd441",
    remote = "https://github.com/0xf005ba11/bazel_ewdk_cc",
    shallow_since = "1700541122 -0700",
)

# tag release-1.12.1 but shallow cloning
git_repository(
    name = "gtest",
    commit = "58d77fa8070e8cec2dc1ed015d66b454c8d78850",
    remote = "https://github.com/google/googletest",
    shallow_since = "1656350095 -0400",
)

load("@bazel_ewdk_cc//:ewdk_cc_configure.bzl", "register_ewdk_cc_toolchains")

register_ewdk_cc_toolchains()
