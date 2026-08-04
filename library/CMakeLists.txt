add_library(
   MyMathLibrary

   src/math/double.cpp
   src/math/vector3.cpp
)

target_include_directories(MyMathLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(MyMathLibrary PUBLIC)