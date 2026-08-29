cmake_minimum_required(VERSION 3.10)
project(ControleDeEstoque VERSION 1.0 LANGUAGES CXX)

# Padrão C++11 ou superior
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executável principal
add_executable(controle_estoque main.cpp)
