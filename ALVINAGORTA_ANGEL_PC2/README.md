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

- Semana: 1 y 3
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
- 0 <= `key` <= 104
- 0 <= `value` <= 105
- Como máximo se realizarán 2 × 10^5 llamadas a `get` y `put`

### Resumen de la solución

Explica brevemente la idea principal de la solución.

### Pseudocódigo


### Puntos a explicar

- HashMap + doubly linked list
- recencia
- operaciones O(1).

### Reto grabado:

- Mostrar el estado de la lista después de una secuencia corta de get/put.

### Complejidad

- Tiempo: O(1) , la que solicita el problema
- Espacio:

### Invariante o idea clave

Describe el invariante o propiedad que se mantiene.

### Preguntas a responder del problema

- ¿Qué representa el frente y el final de la lista?
- ¿Qué haces en get?
- ¿Qué haces en put cuando la clave ya existe?
- ¿Qué haces cuando se excede la capacidad?

### Archivos relevantes

- include/LRUCache.h, DLList.h
- src/LRUCache.cpp
- tests/
- demos/demo_lru.cpp
- benchmark/benchmark.cpp

### Compilación

```bash
cmake -S . -B build
cmake --build build
```

### Ejecución

```bash
./build/tu_programa
```

### Casos de prueba

- Describe al menos 3 casos:
1. Caso pedido en el problema
2. 
3. 

### Historial de commits

Indica que el historial debe verse en el video.

### Declaración de autoría

Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
