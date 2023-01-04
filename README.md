Example bazel project using the EWDK toolchain
========

Project using various bazel features and also building a windows driver using the [EWDK toolchain](https://github.com/0xf005ba11/bazel_ewdk_cc).

## Quick Start

1) Make sure [bazelisk](https://github.com/bazelbuild/bazelisk/releases) is installed and in your path (hint: name the binary bazel.exe).
2) Make sure [git for windows](https://gitforwindows.org/) is installed and in your path.
3) Make sure [bazel buildifier](https://github.com/bazelbuild/buildtools/releases) is installed in your path if you plan to use the vscode bazel extension.
4) Clone this repository and perform an initial build:

```
git clone git@github.com:0xf005ba11/bazel_example_project.git
cd bazel_example_project
bazel build //...
bazel run //exe
bazel test --test_output=all //...
```

## Specifying dbg (debug) or opt (optimized) builds

```
bazel build --compilation_mode=dbg
bazel build --compilation_mode=opt
```

The default mode is "fastbuild" and is equivalent to a debug build.

## Specifying other architectures

```
bazel build --platforms=:windows_x86
bazel build --platforms=:windows_x64
bazel build --platforms=:windows_arm
bazel build --platforms=:windows_arm64
```

> Note: --platforms and --compilation_mode apply to other commands as well such as run and test. 

## Intellisense setup (on windows)

```powershell
copy "$(bazel info output_base)/external/ewdk_cc_configured_toolchain/c_cpp_properties.json" "./.vscode/c_cpp_properties.json"
```