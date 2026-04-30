#include <iostream>
#include "LRUCache.h"

using namespace std;

//Caso de prueba 2
void printGet(LRUCache& cache, int key) {
    cout << cache.get(key);
}

void printPut(LRUCache& cache, int key, int value) {
    cache.put(key, value);
    cout << "null";
}

int main() {

    LRUCache lruCache(1);
    cout << "[null, ";
    printPut(lruCache, 2, 1);
    cout << ", ";
    printGet(lruCache, 2);
    cout << ", ";
    printPut(lruCache, 3, 2);
    cout << ", ";
    printGet(lruCache, 2);
    cout << ", ";
    printGet(lruCache, 3);
    cout << "]" << endl;

    return 0;
}