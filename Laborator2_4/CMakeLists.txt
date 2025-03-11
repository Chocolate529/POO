cmake_minimum_required(VERSION 3.30)
project(Laborator2_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laborator2_4 main.cpp
        domain/medicament.h
        domain/lista.h
        domain/lista.cpp
        service/service_medicamente.h
        service/service_medicamente.cpp
        validator/validator_medicament.h
        validator/validator_medicament.cpp
        prezentare/consola.h
        prezentare/consola.cpp
        teste/test.cpp
        teste/test.h
)