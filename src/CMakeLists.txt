cmake_minimum_required(VERSION 3.0.0)
project(at VERSION 1.0.0
        DESCRIPTION "This library can be used to use streaming devices as input and output devices for the AT instruction set, enabling easy customization of the AT instruction set"
        HOMEPAGE_URL "https://github.com/nayooooo/SDAT.git"
        LANGUAGES "C")

file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/*.c)
set(SRC ${SRC_LIST})
include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)
add_library(at STATIC ${SRC_LIST})
set_target_properties(at PROPERTIES PREFIX "")
