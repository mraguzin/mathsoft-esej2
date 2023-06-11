cmake_minimum_required(VERSION 3.14)
project (sqrt_tests)
set(CMAKE_CXX_STANDARD 20)

add_executable(bit_test bit_po_bit.cpp)
add_executable(adaptive_test heron_adaptivno.cpp)
add_executable(sqrt32_test sqrt32.cpp)
add_executable(sqrt_test sqrt.cpp)
add_executable(sqrt2_test invsqrt.cpp)
