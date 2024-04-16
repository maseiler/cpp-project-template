# C++ Template

## Prerequisites

- [CMake](https://cmake.org/)
- [Clang](https://clang.llvm.org/)
- [pre-commit](https://pre-commit.com/)

Install pre-commit hooks

```bash
pip install pre-commit
pip install clang-format
pre-commit install
# verify
pre-commit run --all-files
```

## Build and Run

Build

```bash
mkdir build && cd build
cmake ..
make
```

Run tests

```bash
./cpp-template-tests
```

Run benchmarks

```bash
./cpp-template-benchmarks
```

## Kudos

to

- https://github.com/dtrussel/cpp_project_template
- https://github.com/TheLartians/ModernCppStarter

for the inspiration.
