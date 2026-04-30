#include <cassert>
#include "LRUCache.h"

int main() {

    // CASO 1
    {
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        assert(cache.get(1) == 1);
        cache.put(3, 3);
        assert(cache.get(2) == -1);
        cache.put(4, 4);
        assert(cache.get(1) == -1);
        assert(cache.get(3) == 3);
        assert(cache.get(4) == 4);
    }

    // CASO 2
    {
        LRUCache cache(1);
        cache.put(2, 1);
        assert(cache.get(2) == 1);
        cache.put(3, 2);
        assert(cache.get(2) == -1);
        assert(cache.get(3) == 2);
    }

    // CASO 3
    {
        LRUCache cache(2);
        cache.put(2, 1);
        cache.put(2, 2);
        assert(cache.get(2) == 2);
        cache.put(1, 1);
        cache.put(4, 1);
        assert(cache.get(2) == -1);
    }

    // CACHE VACIO
    {
        LRUCache cache(2);
        assert(cache.get(1) == -1);
    }

    // ACTUALIZAR VALOR DE CLAVE EXISTENTE
    {
        LRUCache cache(2);
        cache.put(1, 10);
        cache.put(1, 99);
        assert(cache.get(1) == 99);
    }

    // LLENAR CACHE SIN ELIMINAR
    {
        LRUCache cache(3);
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3);
        assert(cache.get(1) == 1);
        assert(cache.get(2) == 2);
        assert(cache.get(3) == 3);
    }

    // REINSERTAR CLAVE ELIMINADA
    {
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3); 
        cache.put(1, 10);
        assert(cache.get(1) == 10);
        assert(cache.get(2) == -1);
        assert(cache.get(3) == 3);
    }

    return 0;
}