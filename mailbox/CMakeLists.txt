cmake_minimum_required(VERSION 2.8)

project (mbxlib)
set(CMAKE_BUILD_TYPE Release)

add_definitions(-DMBX_BUILD_SHARED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/api)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(mbxlib SHARED
    lib/Mailbox.cpp
    lib/mbx/mbx_allocators.cpp
    lib/mbx/mbx_version.cpp
    lib/mbx/mbxlib.cpp)
