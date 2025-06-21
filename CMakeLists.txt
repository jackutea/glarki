cmake_minimum_required(VERSION 3.10)

# Set the project name
project(glarki)

set(CMAKE_C_STANDARD 99)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(SDL3_LIB "$ENV{SDL3_LIB}")
set(SDL3_INC "$ENV{SDL3_INC}")
set(GLAD_LIB "$ENV{GLAD_LIB}")
set(GLAD_INC "$ENV{GLAD_INC}")

# Find packages
include_directories(${SDL3_INC})
include_directories(${GLAD_INC})
include_directories("${PROJECT_SOURCE_DIR}\\include")

# Add source files
file(GLOB SOURCES
    "src/*.c"
    "src/Types/*.c")

# Add executable
add_executable(glarki ${SOURCES})

# Link libraries
link_directories(${SDL3_LIB})
link_directories(${GLAD_LIB})
target_link_libraries(glarki "SDL3.dll")
target_link_libraries(glarki "glad.lib")

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}\\bin")
set_target_properties(glarki PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# Copy SDL3.dll to the output directory
add_custom_command(TARGET glarki POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL3_LIB}\\SDL3.dll"
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}\\Release\\SDL3.dll"
)