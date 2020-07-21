# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(This CPlusPlus)

project (${This} C CXX)

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Include sub-projects.
add_subdirectory ("googletest")
add_subdirectory ("data-structures")

