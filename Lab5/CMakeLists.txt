cmake_minimum_required(VERSION 3.28.3)
project(Lab5 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
add_executable(Lab5 main.c
        domeniu_masina.c
        domeniu_masina.h
        test_masini.c
        test_masini.h
        validator_masina.c
        validator_masina.h
        service_masini.c
        service_masini.h
        ui.c
        ui.h
        domeniu_masina.c
        repo.c
        repo.h
        lista.c
        lista.h)
