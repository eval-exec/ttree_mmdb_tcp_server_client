cmake_minimum_required(VERSION 3.13)
project(key_value_mmdb_via_tcp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(key_value_mmdb_via_tcp

        main.c ttreebuffer.c  ttreebuffer.h  ttree.c  ttree_defs.h  ttree.h  uthash.h hash_table.c hash_table.h

        server_misc.c server_misc.h)
