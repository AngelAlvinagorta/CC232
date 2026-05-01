#include <iostream>
#include "LRUCache.h"

using namespace std;

//Caso de prueba 1 - Caso Principal
void printGet(LRUCache& cache, int key) {
    cout << cache.get(key);
}

void printPut(LRUCache& cache, int key, int value) {
    cache.put(key, value);
    cout << "null";
}

int main() {

    LRUCache cache(2); // Capacidad de 2

    cache.put(1, 10);
    cache.printCache();

    cache.put(2, 20);
    cache.printCache();

    cache.get(1); // Devuelve 10
    cache.printCache();

    cache.put(3, 30);
    cache.printCache();

    return 0;
}