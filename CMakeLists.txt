project(rodos-uart-udp-router)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})

add_subdirectory(rodos)

if(NOT CMAKE_TOOLCHAIN_FILE)
  message("ERROR: no CMAKE_TOOLCHAIN_FILE set!")
endif()

add_executable(router router.cpp)
target_link_libraries(router PUBLIC rodos)
