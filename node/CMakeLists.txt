cmake_minimum_required(VERSION 3.26.4)

project(
    blocky-node
    VERSION 0.1.0
    DESCRIPTION "A simplistic demo blockchain"
    LANGUAGES C
)

set(
    SOURCES
    src/main.c
)

add_executable(blocky_node ${SOURCES})
target_include_directories(blocky_node PRIVATE ./include)
target_link_libraries(blocky_node PRIVATE blocky_core)