cmake_minimum_required(VERSION 3.20)

# Nombre de tu proyecto
project(ValidadorStack)

# Crear el ejecutable a partir de tus archivos fuente (.cpp)
add_executable(demo_stack 
    demo/demo_stack.cpp 
    src/stack.cpp
)

# Indicarle al ejecutable dónde encontrar los archivos de cabecera (.h)
target_include_directories(demo_stack PRIVATE include)