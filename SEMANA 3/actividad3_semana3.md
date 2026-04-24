## Actividad 3-CC232

### Integrante

   * Alvinagorta Huapaya Angel Andres

#### Bloque 1

1. Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.

    * Cuando se pasa de almacenamiento contiguo a dinámico, cambia la facilidad de acceso de rápida a lenta y la facilidad de modificar de lenta a rápida.

2. Expliquen la diferencia entre acceso por rango y acceso por posición o enlace.

    * En el acceso por rango para acceder a un elemento se usa un indice (0, 1, 2, ... n-1), se suele usar en arrays y vectores, mientras que en el acceso por posición o enlace para acceder a un elemento se usa punteros de nodo a nodo, se suele usar en SLList y DLList.

3. Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.

    * Esto es debido a que presenta la ventaja de no ser necesario organizar ni desplazar elementos, solo cambiar enlaces. Pero si se busca acceder por indice el costo total es `O(n)`.

4. Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.

5. Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.

6. Expliquen qué aporta el nodo centinela `dummy` en `DLList`.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

8. Expliquen cuál es la idea espacial central de `SEList`.

9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

#### Bloque 2

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

#### Bloque 3
(respuestas)

#### Bloque 4
(respuestas)

#### Bloque 5
(respuestas)

#### Bloque 6
(respuestas)

#### Bloque 7
(respuestas)

#### Bloque 8
(respuesta final)

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación: