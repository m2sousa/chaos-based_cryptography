cmake_minimum_required(VERSION 3.14)
project(chaos-based_cryptography)

# Adding the Python header for matplotlibcpp.h
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

file(GLOB_RECURSE TARGET_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_executable(chaos-based_cryptography ${TARGET_SOURCES})

# Linking the Python header
target_link_libraries(chaos-based_cryptography ${PYTHON_LIBRARIES})
