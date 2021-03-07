# cppcalculator

A basic calculator program for learning c++ / cmake


# Build instructions

Building the source code is as follows:

Make a build directory:

```bash
mkdir build
```

## (optional) Specify the compiler using environment variables

By default (if you don't set environment variables CC and CXX), the system default compiler will be used. Conan and CMake use the environment variables CC and CXX to decide which compiler to use. So to avoid the conflict issues only specify the compilers using these variables.

CMake will detect which compiler was used to build each of the Conan targets. If you build all of your Conan targets with one compiler, and then build your CMake targets with a different compiler, the project may fail to build.Commands for setting the compilers

## Configure your build

To configure the project and write makefiles, you could use cmake with a bunch of command line options. The easier option is to run cmake interactively:

```bash
ccmake -S . -B build
```

## building
When configuration is complete, do:

```bash
cmake --build ./build
```

## Running tests
You can run the tests by executing the compiled binary,  or by running ctest

```bash
cd build
ctest
```
