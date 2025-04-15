cmake_minimum_required(VERSION 3.30)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6 main.cpp
        domeniu_masina.cpp
        domeniu_masina.h
        repo_masina.cpp
        repo_masina.h
        service_masina.cpp
        service_masina.h
        list.h
        ui.cpp
        ui.h
        teste.cpp
        teste.h)
