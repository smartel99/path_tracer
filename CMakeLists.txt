cmake_minimum_required(VERSION 3.21)
project(path_tracer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
        utils/*.*
        renderer/*.*
        math/*.*
        )

set(SOURCES
        ${SOURCES}
        "./main.cpp"
        "./vendor/stb/impl.cpp"
        )

message(STATUS ${SOURCES})


add_executable(path_tracer ${SOURCES})

target_link_libraries(path_tracer
        Argengine_static)


add_subdirectory(vendor/argengine EXCLUDE_FROM_ALL)
include_directories(vendor/argengine/src)

set(PRJ_FLAGS)
set(ARGENGINE_FLAGS)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(PRJ_FLAGS "${PRJ_FLAGS} /W4 /permissive- /Zc:preprocessor")
    set(ARGENGINE_FLAGS "${ARGENGINE_FLAGS} /w")
    set(DASH_O3_FLAG /O2)
    set(DASH_OS_FLAG /O1)
    set(DASH_O0_FLAG /Od)
    set(DASH_G_FLAG /Zi)
else ()
    set(PRJ_FLAGS "${PRJ_FLAGS} -Wall -Wextra -Wpedantic")
    set(ARGENGINE_FLAGS "${ARGENGINE_FLAGS} -w")
    set(DASH_O3_FLAG -Ofast)
    set(DASH_OS_FLAG -Os)
    set(DASH_O0_FLAG -O0)
    set(DASH_G_FLAG -g)
endif ()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    set(PRJ_FLAGS "${PRJ_FLAGS} ${DASH_O3_FLAG}")
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    set(PRJ_FLAGS "${PRJ_FLAGS} ${DASH_O3_FLAG} ${DASH_G_FLAG}")
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    set(PRJ_FLAGS "${PRJ_FLAGS} ${DASH_OS_FLAG}")
else ()
    message(STATUS "Minimal optimization, debug info included")
    set(PRJ_FLAGS "${PRJ_FLAGS} ${DASH_O0_FLAG} ${DASH_G_FLAG}")
    add_definitions(-DDEBUG)
endif ()

set_target_properties(path_tracer PROPERTIES COMPILE_FLAGS ${PRJ_FLAGS})
set_target_properties(Argengine PROPERTIES COMPILE_FLAGS ${ARGENGINE_FLAGS})
include_directories(
        vendor/spdlog/include
        vendor
        .
)

