# rodos-uart-udp-router

Routes Rodos gateway messages between the UART and UDP network interface.

## Usage

This project uses the CMake build pipeline.

1. Build the project using the following commands:

```shell
cd cmake-build-debug
cmake -DCMAKE_TOOLCHAIN_FILE=../rodos/cmake/port/linux-x86.cmake -DEXECUTABLE=ON ..
make all
```

2. Run the executable:

```shell
./router
```
