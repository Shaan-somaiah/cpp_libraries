cmake_minimum_required(VERSION 3.16)
project(
    cpp_libraries 
    VERSION 0.1.0
    LANGUAGES CXX
)

option(CMAKE_EXPORT_COMPILE_COMMANDS "Generate compile_commands.json" ON)

include(cmake/CompilerOptions.cmake)
include(cmake/Dependencies.cmake)

add_subdirectory(src)

option(CPP_LIBRARIES_BUILD_TESTS "Build cpp_libraries tests" ON)

if(CPP_LIBRARIES_BUILD_TESTS AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  enable_testing()
  add_subdirectory(test)
endif()
