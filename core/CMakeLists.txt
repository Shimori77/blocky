cmake_minimum_required(VERSION 3.26.4)

project(
    blocky-core
    VERSION 0.1.0
    DESCRIPTION "A simplistic demo blockchain"
    LANGUAGES C
)

set(
    SOURCES
    src/wallet.c
)

add_library(blocky_core SHARED ${SOURCES})
target_include_directories(blocky_core PUBLIC ./include)
target_link_libraries(blocky_core PUBLIC ed25519 rpmalloc)
