cmake_minimum_required(VERSION 3.10)  # Minimum version of CMake required
project(obstacle_map_task)            # Name of your project

# Force Google Test to use the same runtime library as your code
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add Google Test
enable_testing()
add_subdirectory(googletest)  # Path to the Google Test directory in your project
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Set the compile flags for Debug and Release mode
set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
set(CMAKE_CXX_FLAGS_RELEASE "/MD")
set(CMAKE_CXX_STANDARD 17) # Use C++17 standard

# Suppress the LNK4098 warning
add_definitions( "/D_CRT_SECURE_NO_WARNINGS /wd4005 /wd4996 /nologo" )

# Find the Python interpreter and libraries
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Include the Python headers
include_directories(${Python_INCLUDE_DIRS})

# Include the NumPy headers
include_directories("C:/Python312/Lib/site-packages/numpy/core/include")

file(GLOB APP_SOURCES "src/*.cpp" "inc/*.h")
list(REMOVE_ITEM APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")

# Create an executable for your main application
add_executable(main ${APP_SOURCES} "src/main.cpp")

# Link against the Python libraries when building your executable
target_link_libraries(main ${Python_LIBRARIES})

# Create an executable for your tests
add_executable(runUnitTests ${APP_SOURCES} ${TEST_SOURCES})
# Link Google Test to the test executable
target_link_libraries(runUnitTests gtest gtest_main ${Python_LIBRARIES})
# Add a test to CMake
add_test(NAME MyGoogleTest COMMAND runUnitTests)