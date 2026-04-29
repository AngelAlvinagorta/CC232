#include <iostream>
#include "LRUCache.h"

void printGet(LRUCache& cache, int key) {
    std::cout << cache.get(key);
}

void printPut(LRUCache& cache, int key, int value) {
    cache.put(key, value);
    std::cout << "null";
}

int main() {

    LRUCache lruCache(2);
    std::cout << "[null, ";
    printPut(lruCache, 1, 1);
    std::cout << ", ";
    printPut(lruCache, 2, 2); 
    std::cout << ", ";
    printGet(lruCache, 1);
    std::cout << ", ";
    printPut(lruCache, 3, 3);
    std::cout << ", ";
    printGet(lruCache, 2);
    std::cout << ", ";
    printPut(lruCache, 4, 4);
    std::cout << ", ";
    printGet(lruCache, 1);
    std::cout << ", ";
    printGet(lruCache, 3);
    std::cout << ", ";
    printGet(lruCache, 4);
    std::cout << "]" << std::endl;

    return 0;
}