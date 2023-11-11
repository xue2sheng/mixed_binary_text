enable_testing()

add_executable(TestSimple TestSimple.cpp)
target_link_libraries(TestSimple PUBLIC mbt-static)
add_test(NAME TestSimple COMMAND $<TARGET_FILE:TestSimple>)