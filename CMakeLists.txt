cmake_minimum_required(VERSION 3.27)
project(mixed_binary_text)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.82 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_executable(mixed_binary_text main.cpp)
target_link_libraries(mixed_binary_text PUBLIC Boost::program_options)
