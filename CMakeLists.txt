cmake_minimum_required(VERSION 3.24)
project(esameLabGestione)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES Finanza.h Finanza.cpp
        Account.h Account.cpp
        Carte.h Carte.cpp
        Transazione.h Data.h
        )

add_executable(esameLabGestione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(esameLabGestione core)
