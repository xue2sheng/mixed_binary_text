cmake_minimum_required(VERSION 3.27)
project(mbt)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.82 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR} include)

file(GLOB LIB_SOURCE_FILES src/lib.cpp)
add_library(mbt-static STATIC ${LIB_SOURCE_FILES})
include(CTest)
add_subdirectory(test)

add_library(mbt-shared SHARED ${LIB_SOURCE_FILES})
target_link_libraries(mbt-shared PUBLIC mbt-static)
set_target_properties(mbt-shared PROPERTIES OUTPUT_NAME mbt)

add_executable(mbt src/main.cpp)
target_link_libraries(mbt PUBLIC mbt-static Boost::program_options)
add_dependencies(mbt mbt-shared)
