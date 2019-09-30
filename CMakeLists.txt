cmake_minimum_required(VERSION 3.14)
project(Arbol_operaciones)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arbol_operaciones main.cpp ExpressionTree.h Evaluador.h Operations.h)