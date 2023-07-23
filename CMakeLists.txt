cmake_minimum_required(VERSION 3.26.4)

project(
    blocky
    VERSION 0.1.0
    DESCRIPTION "A simplistic demo blockchain"
    LANGUAGES C
)

add_subdirectory(lib/ed25519)
add_subdirectory(lib/rpmalloc)

add_subdirectory(core)
add_subdirectory(node)

add_dependencies(blocky_core ed25519 rpmalloc)
add_dependencies(blocky_node blocky_core)