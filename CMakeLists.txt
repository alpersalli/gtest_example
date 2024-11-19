cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Enable code coverage flags for GCC or Clang compilers
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()

# Include math_operations headers if necessary (update this to your own file paths)
include_directories(${CMAKE_SOURCE_DIR})

# Add source files (adjust file names to match your project structure)
set(SOURCES
    math_operations.c  # Add your math operations C file
    hello_test.cc     # Your test file
)

# Define the test executable
add_executable(hello_test ${SOURCES})

# Link the GoogleTest libraries to the test executable
target_link_libraries(
  hello_test
  GTest::gtest_main
  gmock
)

# Discover and run the tests
include(GoogleTest)
gtest_discover_tests(hello_test)
