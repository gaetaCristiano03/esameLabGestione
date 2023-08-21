cmake_minimum_required(VERSION 3.24)
project(esameLabGestione)

set(CMAKE_CXX_STANDARD 17)

add_executable(esameLabGestione main.cpp Finanza.h Finanza.cpp Account.h Account.cpp Carte.h Carte.cpp Transazione.h Transazione.cpp Data.h)
