#pragma once

class Stack{
    private:
        char* arreglo;
        int indiceTope;
        int capacidad;
    public:
        // Constructor
        Stack(int tamano);
        ~Stack();

        // Métodos principales
        void push(char c);
        void pop();
        char top();
        bool isEmpty();
};