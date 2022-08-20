# Project definitions
cmake_minimum_required(VERSION 3.2)
project(compiled_program C)

# Project options
add_definitions(-std=c89)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
set(CMAKE_C_FLAGS "-Weverything -pedantic-errors")

# Get all sources
file(GLOB_RECURSE SOURCES "src/*.c" main.c)

# Get all resources
set (source "${CMAKE_SOURCE_DIR}/data")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/data")

add_custom_target(data)

file(TO_NATIVE_PATH "${CMAKE_SOURCE_DIR}/data" source)
file(TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}/data" destination)

if (WIN32)
  add_custom_command(
    TARGET data POST_BUILD
    COMMAND mklink /D ${destination} ${source}
    DEPENDS ${destination}
    COMMENT "symbolic link data folder from ${source} => ${destination}"
  )
else()
  add_custom_command(
    TARGET data POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link data folder from ${source} => ${destination}"
  )
endif()

# Create executable and add dependencies
add_executable(compiled_program ${SOURCES})
add_dependencies(compiled_program data)
