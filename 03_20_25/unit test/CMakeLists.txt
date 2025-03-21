cmake_minimum_required(VERSION 3.8.2)

# set the project name
project(Test)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(student SHARED donut.cpp)

 
# Link runTests with what we want to test and the GTest and pthread library

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -Wl,--wrap=main")


add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} student pthread)
