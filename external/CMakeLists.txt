
include(FetchContent)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)

if (WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings (from quickstart guide)
endif()

FetchContent_MakeAvailable(googletest)