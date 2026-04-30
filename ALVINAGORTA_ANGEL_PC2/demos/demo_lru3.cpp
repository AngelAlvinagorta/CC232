#include <iostream>
#include "LRUCache.h"

using namespace std;

//Caso de prueba 3 - Caso Borde
void printGet(LRUCache& cache, int key) {
    cout << cache.get(key);
}

void printPut(LRUCache& cache, int key, int value) {
    cache.put(key, value);
    cout << "null";
}

int main() {

    LRUCache lruCache(2);
    cout << "[null, ";
    printPut(lruCache, 2, 1); 
    cout << ", ";
    printPut(lruCache, 2, 2);
    cout << ", ";
    printGet(lruCache, 2);
    cout << ", ";
    printPut(lruCache, 1, 1);
    cout << ", ";
    printPut(lruCache, 4, 1);
    cout << ", ";
    printGet(lruCache, 2);
    cout << "]" << endl;

    return 0;
}