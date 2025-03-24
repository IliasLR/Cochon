cmake_minimum_required(VERSION 3.30)
project(jeu_de_cochon C)

set(CMAKE_C_STANDARD 11)


add_compile_options(-g -std=c99 -O0 -pedantic -pedantic-errors -Wall -Wbad-function-cast
        -Wcast-align=strict -Wcast-qual -Werror -Wextra -Wfloat-equal -Wformat=2
        -Winit-self -Winline -Wlogical-op -Wnested-externs -Wredundant-decls -Wshadow
        -Wstrict-aliasing -Wstrict-overflow=3 -Wstrict-prototypes -Wundef -Wuninitialized
        -Wwrite-strings -fanalyzer -D_DEFAULT_SOURCE)


add_executable(jeu_de_cochon main.c
)
