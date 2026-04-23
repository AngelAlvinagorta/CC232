## Actividad 2-CC232

### Integrante

   * Alvinagorta Huapaya Angel Andres

#### Bloque 1 - Núcleo conceptual de la semana

1. Explique con sus palabras qué significa que un arreglo use memoria contigua.

   * Significa que todos sus elementos se almacenan uno después de otro en un bloque continuo de memoria.

2. Explique por qué acceder a `A[i]` es una operación de costo `O(1)`.

   * Porque se calcula directamente la dirección del elemento sin tener que recorrer otros.

3. Explique la diferencia entre `size` y `capacity`.

   * `size` es la cantidad actual de elementos que el arreglo contiene.
   * `capacity` es el número de elementos que el arreglo puede almacenar.

4. Explique por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.

   * Esto es debido a que un arreglo dinámico usa un bloque contiguo de memoria y al requerir más espacio se necesitará un bloque más grande que incluya sus elementos antiguos juntos.

5. Explique por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.

   * Copiar `n` elementos cuesta `O(n)` y despues de cada copia hay espacio para `n` inserciones sin nuevos costos, por lo que el costo de la copia se reparte entre las inserciones adicionales y cada inserción tendria un costo constante. 

6. Compare `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?

   * **Comparten**:
      * Ambas almacenan elementos en un bloque de memoria contigua.
      * Ambas duplican su capacidad cuando se llenan garantizando que insertar elementos al final tome tiempo `O(1)`.
      * Ambas implementan un mecanismo para encogerse cuando la cantidad de elementos cae por debajo de la capacidad máxima.

   * **Cambian en Interfaz**:
      | Caracteristica | `ArrayStack` | `DengVector` |
      |---|---|---|
      | Acceder a elementos | `get(i)`, `set(i, x)` | `v[i]` |
      | Insertar elementos | `add(i, x)` | `insert(r, e)` |
      | Eliminar elementos | `remove(i)` | `remove(r)` |
   
   * **Cambian en intención didáctica**:
      * `ArrayStack` se enfoca netamente en la lógica del algoritmo ignorando conceptos avanzados. 
      * `DengVector` se enfoca en enseñar a construir estructuras utilizando características avanzadas.

7. Explique qué mejora `FastArrayStack` respecto a `ArrayStack`.

   * A diferencia de `ArrayStack` que emplea un bucle `for` para mover elementos uno por uno, `FastArrayStack` utiliza un enfoque en bloque evitando sobrecarga de bucles. 

8. Explique cuál es la idea espacial central de `RootishArrayStack`.

   * Reducir drásticamente la memoria desperdiciada en un arreglo dinámico, manteniendo al mismo tiempo un tiempo de lectura y escritura rápido.

9. Explique por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.

   * `RootishArrayStack`usa estos bloques para guarda los elementos en una lista de arreglos más pequeños. El tamaño de estos bloques crece linealmente (El bloque `0` tiene tamaño `1`, el bloque `1` tiene tamaño `2`, ... , el bloque `b` tiene tamaño `b+1`)

10. Explique qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.

   * Si la representación es un único bloque continuo, el costo temporal será bajo, pero el desperdicio espacial será alto `O(n)`.
   * Si la representación son bloques fragmentados matemáticamente, el desperdicio espacial será bajo `O(√n)`, pero el costo temporal real será más alto.

#### Bloque 2 - Demostración y trazado guiado
Construye una tabla con cuatro columnas:
- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo o espacio

1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?

2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?

3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?

4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?

5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?

6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?

7. ¿Qué demo sirve mejor para defender amortización y cuál sirve mejor para defender uso de espacio?

#### Bloque 3 - Pruebas públicas, stress y correctitud
1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?

2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?

3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?

4. ¿Qué sí demuestra una prueba pública sobre una estructura?

5. ¿Qué no demuestra una prueba pública?

6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?

7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

#### Bloque 4 - Vector como puente entre teoría y código
1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?

2. ¿Cuándo debe ejecutarse `expand()`?

3. ¿Por qué `insert(r, e)` necesita desplazar elementos?

4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?

5. ¿Qué evidencia de copia profunda aparece en la demo?

6. ¿Por qué `traverse()` es una buena interfaz didáctica?

7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?

#### Bloque 5 - RootishArrayStack: espacio y mapeo
1. ¿Cómo se distribuyen los elementos entre bloques?

2. ¿Por qué con `r` bloques la capacidad total es `r(r+1)/2`?

3. ¿Qué problema resuelve `i2b(i)`?

4. ¿Qué información produce `locate(i)` en la versión explicada?

5. ¿Qué se gana en espacio frente a `ArrayStack`?

6. ¿Qué se conserva igual respecto a la interfaz?

7. ¿Qué parte les parece más difícil de defender oralmente: el mapeo, el análisis espacial o el costo amortizado de `grow/shrink`?

#### Bloque 6 - Refuerzo de lectura
Revisa: Lectura4-Deng

1. ¿Qué aporta operator[] a la idea de vector?

2. ¿Qué supone find(e) sobre igualdad entre elementos?

3. ¿Qué muestra traverse() sobre procesamiento uniforme de toda la estructura?

4. ¿Por qué esta lectura sirve como refuerzo natural de DengVector aunque no sea el centro exclusivo de la semana?

#### Bloque 7 - Cierre comparativo
¿Qué cambia cuando pasamos de "usar un arreglo" a "diseñar una estructura dinámica basada en arreglo"?

La respuesta debe incluir obligatoriamente:

una afirmación sobre representación
una afirmación sobre correctitud
una afirmación sobre costo amortizado
una afirmación sobre uso de espacio
una comparación entre ArrayStack, FastArrayStack y RootishArrayStack.

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación:

