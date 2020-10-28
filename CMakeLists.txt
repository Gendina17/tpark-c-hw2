cmake_minimum_required(VERSION 3.17)
project(Homework2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "--coverage")

add_executable(Homework2 main.c consist_static/logic_consist.c consist_static/logic_consist.h parallel_dynamic/logic_parallel.c parallel_dynamic/logic_parallel.h input_output.c input_output.h file_creation.c file_creation.h)

add_library(consist_static STATIC consist_static/logic_consist.c consist_static/logic_consist.h)
add_library(parallel_dynamic SHARED parallel_dynamic/logic_parallel.c parallel_dynamic/logic_parallel.h)

target_link_libraries(${APP_NAME} consist_static)
target_link_libraries(${APP_NAME} parallel_dynamic)

include_directories(include)

set(HEADER_FILES
        consist_static/logic_consist.h
        parallel_dynamic/logic_parallel.h
        )

set(SOURCE_FILES
        consist_static/logic_consist.c
        parallel_dynamic/logic_parallel.c
        )
add_subdirectory(Google_tests)

if ("${TARGET_CPU}" STREQUAL "amd64")
    set (CMAKE_SIZEOF_VOID_P 8)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
elseif ("${TARGET_CPU}" STREQUAL "x86")
    set (CMAKE_SIZEOF_VOID_P 4)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)

    if (GCC)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
        set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32")
    endif ()
else ()

endif ()