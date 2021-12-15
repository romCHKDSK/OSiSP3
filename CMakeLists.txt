cmake_minimum_required(VERSION 3.0)

project(lr2 LANGUAGES C)

add_executable(lr2 main.c)

install(TARGETS lr2 RUNTIME DESTINATION bin)
