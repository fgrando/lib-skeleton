cmake_minimum_required(VERSION 2.8)



project (mbxlib)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_definitions(-DMBX_BUILD_SHARED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/api)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(mbxlib SHARED
    lib/Mailbox.cpp
    lib/mbx/mbx_allocators.cpp
    lib/mbx/mbx_version.cpp
    lib/mbx/mbxlib.cpp)
