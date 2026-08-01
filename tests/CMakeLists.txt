enable_testing()

add_executable(vector3_test math/vector3_test.cpp)
target_link_libraries(vector3_test GTest::gtest_main MyMathLibrary)

include(GoogleTest)
gtest_discover_tests(vector3_test)