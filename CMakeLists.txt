cmake_minimum_required(VERSION 3.20)
project(fantasyFightingGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(fantasyFightingGame main.cpp Saloon.cpp Saloon.h Cowboy.cpp Cowboy.h Weapon.cpp Weapon.h Hero.cpp Hero.h Gunstore.cpp Gunstore.h Drinks.cpp Drinks.h)
