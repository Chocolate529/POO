cmake_minimum_required(VERSION 3.30)
project(Lab10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp")


add_executable(Lab10 ${SOURCES} main.cpp)

target_include_directories(Lab10 PRIVATE ${INCLUDE_DIR})
target_include_directories(Lab10 PRIVATE ${SOURCE_DIR})

target_link_libraries(Lab10 Qt6::Widgets)