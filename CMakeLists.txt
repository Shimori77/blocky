cmake_minimum_required(VERSION 3.27)

project(
    blocky
    VERSION 0.1.0
    DESCRIPTION "A simplistic demo blockchain"
    LANGUAGES C
)

add_subdirectory(lib/ed25519)
add_subdirectory(lib/rpmalloc)

add_subdirectory(core)