# rodos-uart-udp-router

Routes Rodos gateway messages between the UART and UDP network interface.

## Usage

This project uses the CMake build pipeline.

1. Clone the project and update the submodules:

```shell
git clone git@github.com:fussel178/rodos-uart-udp-router.git
cd rodos-uart-udp-router
git submodule update --init --recursive
```

2. Build the project using the following commands:

```shell
cd cmake-build-debug
cmake -DCMAKE_TOOLCHAIN_FILE=../rodos/cmake/port/linux-x86.cmake -DEXECUTABLE=ON ..
make all
```

3. Run the executable:

```shell
./router
```

## Making changes

This project uses the Rodos router to transfer messages between both interfaces.
Most of the configurable parameters are in the top region of the `router.cpp` file defined as macros.
Change the parameters and recompile the project before testing the changes.
