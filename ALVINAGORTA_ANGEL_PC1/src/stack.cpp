#include "Stack.h"

Stack::Stack(int tamano) {
    capacidad = tamano;
    arreglo = new char[tamano];
    indiceTope = -1;
}

Stack::~Stack() {
    delete[] arreglo;
}

void Stack::push(char c) {
    if (indiceTope < capacidad - 1) {
        indiceTope++;
        arreglo[indiceTope] = c;
    }
}

void Stack::pop() {
    if (!isEmpty()) {
        indiceTope--;
    }
}

char Stack::top() {
    if (!isEmpty()) {
        return arreglo[indiceTope];
    }
    return '\0';
}

bool Stack::isEmpty() {
    return indiceTope == -1;
}