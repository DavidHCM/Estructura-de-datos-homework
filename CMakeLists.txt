cmake_minimum_required(VERSION 3.24)
project(Estructura_de_datos_homework C)

set(CMAKE_C_STANDARD 11)

include_directories("Home-act-repo 10/Act-1")
include_directories("Home-act-repo 10/Act-2")
include_directories("Home-act-repo 16/Act-1")
include_directories("Home-act-repo 17/Act-1")
include_directories("Home-act-repo 18/Act-1")
include_directories("Home-act-repo 19/Act-1")
include_directories("Home-act-repo 20/Act-1")
include_directories("Home-act-repo 21/Act-1")

add_executable(Estructura_de_datos_homework
        "Home-act-repo 21/Act-1/datatypes.c"
        "Home-act-repo 21/Act-1/datatypes.h"
        "Home-act-repo 21/Act-1/stack.c"
        "Home-act-repo 21/Act-1/stack.h"
        "Home-act-repo 21/Act-1/ejer1.c"
        "Home-act-repo 21/Act-1/fuente.txt"
        )
