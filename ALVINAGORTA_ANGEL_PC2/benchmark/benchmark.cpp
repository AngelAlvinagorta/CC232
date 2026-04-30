#include <iostream>
#include <chrono>
#include <random>
#include "LRUCache.h"

using namespace std;
using namespace std::chrono;

int main() {
    mt19937 rng(42);
    uniform_int_distribution<int> keyDist(0, 10000);
    uniform_int_distribution<int> valDist(0, 100000);
    uniform_int_distribution<int> opDist(0, 1);

    int repeticiones = 200000;

    cout << "Operaciones por prueba: " << repeticiones << "\n" << endl;

    // CAPACITY 1
    LRUCache cache1(1);
    auto inicio1 = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; i++) {
        int key = keyDist(rng);
        if (opDist(rng) == 0) {
            cache1.get(key);
        } else {
            cache1.put(key, valDist(rng));
        }
    }
    auto fin1 = high_resolution_clock::now();
    auto duracion1 = duration_cast<milliseconds>(fin1 - inicio1);

    // CAPACITY 100
    LRUCache cache2(100);
    auto inicio2 = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; i++) {
        int key = keyDist(rng);
        if (opDist(rng) == 0) {
            cache2.get(key);
        } else {
            cache2.put(key, valDist(rng));
        }
    }
    auto fin2 = high_resolution_clock::now();
    auto duracion2 = duration_cast<milliseconds>(fin2 - inicio2);

    // CAPACITY 1000
    LRUCache cache3(1000);
    auto inicio3 = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; i++) {
        int key = keyDist(rng);
        if (opDist(rng) == 0) {
            cache3.get(key);
        } else {
            cache3.put(key, valDist(rng));
        }
    }
    auto fin3 = high_resolution_clock::now();
    auto duracion3 = duration_cast<milliseconds>(fin3 - inicio3);

    // CAPACITY 3000 CASO LIMITE
    LRUCache cache4(3000);
    auto inicio4 = high_resolution_clock::now();
    for (int i = 0; i < repeticiones; i++) {
        int key = keyDist(rng);
        if (opDist(rng) == 0) {
            cache4.get(key);
        } else {
            cache4.put(key, valDist(rng));
        }
    }
    auto fin4 = high_resolution_clock::now();
    auto duracion4 = duration_cast<milliseconds>(fin4 - inicio4);

    cout << "RESULTADOS:" << endl;
    cout << "capacity=1   , Tiempo : " << duracion1.count() << " ms" << endl;
    cout << "capacity=100 , Tiempo : " << duracion2.count() << " ms" << endl;
    cout << "capacity=1000, Tiempo : " << duracion3.count() << " ms" << endl;
    cout << "capacity=3000, Tiempo : " << duracion4.count() << " ms" << endl;

    return 0;
}