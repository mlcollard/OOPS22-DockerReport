# @file CMakeLists.txt
# 
# CMake files for the DockerReport project

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.19)

# project info
project(DockerReport)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Use Release build type if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Source files for the main program DockerReport
set(SOURCE DockerReport.cpp YAMLParser.cpp yaml_parser.cpp)

# srcFact application
add_executable(DockerReport ${SOURCE})

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Extract the demo input srcML file
file(ARCHIVE_EXTRACT INPUT ${CMAKE_SOURCE_DIR}/dockercompose.yml.zip)

# Demo run command
add_custom_target(run
        COMMENT "Run demo"
        COMMAND time ./DockerReport < dockercompose.yml
        DEPENDS DockerReport
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
