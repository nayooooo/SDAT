cmake_minimum_required(VERSION 3.0.0)
project(at_test VERSION 1.0.0
        DESCRIPTION "Verify AT instruction set functionality"
        LANGUAGES "C")

file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/*.c)
set(SRC ${SRC_LIST})
include_directories(${PROJECT_SOURCE_DIR}/../../src/include)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} PUBLIC
                        ${PROJECT_SOURCE_DIR}/../../lib/at.a)
