## PC2 - CC232

### Estudiante

- Nombre: Alvinagorta Huapaya Angel Andres
- Código: 20210047H
- Problema asignado: LRU Cache
- Enlace: https://leetcode.com/problems/lru-cache/description/

### Referencia oficial

- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal

- Semanas: 2 y 3
- Estructura o técnica principal: `HashMap` + `doubly linked list`

### Especificación del problema

- Diseña una estructura de datos que cumpla con las restricciones de una caché LRU (Least Recently Used / Menos Recientemente Usado).
- Implementa la clase `LRUCache`:

  - `LRUCache(int capacity)` Inicializa el caché LRU con una capacidad de tamaño positivo llamada `capacity`.
  - `int get(int key)` Devuelve el valor de la clave `key` si existe, en caso contrario, devuelve `-1`.
  - `void put(int key, int value)` Actualiza el valor de la clave `key` si ya existe. De lo contrario, agrega el par `key-value` al caché. Si al hacer esta operación el número de claves supera la capacidad `capacity`, elimina la clave menos usada recientemente.

- Las funciones `get` y `put` deben ejecutarse cada una con una complejidad promedio de tiempo `O(1)`.

### Restricciones

- 1 <= `capacity` <= 3000
- 0 <= `key` <= 10^4
- 0 <= `value` <= 10^5
- Como máximo se realizarán 2 × 10^5 llamadas a `get` y `put`

### Resumen de la solución

- El problema es lograr **O(1)** en ambas funciones `get` y `put`, por lo que se uso una "tabla hash" (`HashMap`) que permite buscar por clave en `O(1)`, pero no puede mantener el orden de uso ni desalojar el menos reciente de forma eficiente por lo que se le combinó con una "lista doblemente enlazada" (`doubly linked list`) que permite insertar y eliminar nodos en `O(1)` y buscar por clave en `O(n)`.

### Puntos a explicar

- HashMap + doubly linked list
- recencia
- operaciones O(1).

### Reto grabado:

- Mostrar el estado de la lista después de una secuencia corta de get/put.

### Complejidad

- Tiempo: O(1), la que solicita el problema
- Espacio: O(n)

### Invariante o idea clave

* El elemento en `dummy.prev` debe ser al que se accedio menos recientemente, y el elemento en `dummy.next` debe ser al que se accedio más recientemente.

### Preguntas a responder del problema

- ¿Qué representa el frente y el final de la lista?
  * El frente (`dummy.next`) es el elemento más recientemente usado y el final (`dummy.prev`) es el elemento menos recientemente usado y el próximo en ser desalojado.
- ¿Qué haces en `get`?
  * Si la clave no existe retorno da `-1` y en caso si exista, se mueve el nodo al frente para marcarlo como el más recientemente usado y se retorna su valor.
- ¿Qué haces en `put` cuando la clave ya existe?
  * Actualizo su valor y muevo el nodo al frente. No se crea un nodo nuevo ni se desaloja ningún elemento.
- ¿Qué haces cuando se excede la capacidad?
  * Se elimina el nodo en `dummy.prev` y se borra su entrada del `hashMap` e inserta el nuevo nodo al frente.

### Archivos relevantes

- include/LRUCache.h, DLList.h
- src/LRUCache.cpp
- tests/test_lru.cpp
- demos/demo_lru.cpp, demo_lru2.cpp, demo_lru3.cpp
- benchmark/benchmark.cpp

### Compilación

```bash
cmake -S . -B build
cmake --build build
```

### Ejecución

- Caso 1:
```bash
./build/pc2_demo_lru.exe
```

- Caso 2:
```bash
./build/pc2_demo_lru2.exe
```

- Caso 3:
```bash
./build/pc2_demo_lru3.exe
```

- Caso 4:
```bash
./build/pc2_demo_lru4.exe
```

- Benchmark:
```bash
./build/pc2_benchmark.exe
```

- Test:
```bash
./build/pc2_test.exe
```

### Casos de prueba

- Describe al menos 3 casos:
1. Caso principal
  * Caso pedido en el problema asignado
2. Caso estandar
  * Este caso prueba que con `capacity=1` cada `put` de una clave nueva se desaloja la única clave existente.
3. Caso borde
  * Este caso prueba que hacer `put` con una clave que ya existe solo actualiza su valor y la mueve al frente, sin aumentar el tamaño del cache ni desalojar nada.

### Historial de commits

1. Añadiendo Includes y Ordenando README
2. Añadiendo LRUCache.cpp, demo_lru.cpp y CMakeLists.txt
3. Añadiendo Benchmark y 2 casos más de prueba
4. Añadiendo test_lru.cpp y ajustando CMakeLists para su funcionamiento
5. Añadiendo resultados, video y diapositiva usada en el explicación

### Declaración de autoría

Yo Angel Alvinagorta Huapaya, declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
