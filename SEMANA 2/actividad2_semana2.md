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

   | Archivo | Salida/observable importante | Idea estructural | Argumento de costo o espacio |
   |---|---|---|---|
   | `demo_array_basico.cpp` | El valor de `b.length` y su contenido  después de ejecutar `b = a`.| Arreglo de tamaño fijo con un mecanismo de asignación por transferencia de propiedad | Evita el costo temporal de `O(n)` de una copia profunda al transferir únicamente el control del bloque de memoria. |
   | `demo_arraystack.cpp` | La impresión del `size` y el contenido antes y después de usar `add` y `remove`. | Implementación estándar de una pila sobre un arreglo dinámico continuo. | Muestra de que la estructura crece y decrece lógicamente, manteniendo el acceso por índice. |
   | `demo_arraystack_explicado.cpp` | Mensajes explícitos en consola detallando "Se desplazan a la derecha/izquierda..." al insertar o eliminar, usando `debug_print`. | Versión que hace visible el mecanismo interno de mover elementos para abrir o cerrar huecos. | Muestra por qué las operaciones `add(i, x)` y `remove(i)` tienen una penalidad de tiempo de `O(n-i)`. |
   | `demo_fastarraystack.cpp` | Ejecución de inserción en el medio idéntica en salida, pero sin bucles `for` internos. | Reemplazo de las iteraciones manuales por copias de memoria en bloque. | Mantiene la complejidad asintótica de `O(n-i)`, pero reduce drásticamente las constantes ocultas. |
   | `demo_rootisharraystack.cpp` | La iteración transparente de elementos mediante `get(i)` a pesar de estar en distintos bloques. | Implementación de memoria distribuida en bloques fragmentados que crecen en progresión aritmética. | La complejidad de la estructura interna es invisible para el usuario, operando como un solo arreglo. |
   | `demo_rootisharraystack_explicado.cpp` | La función `print_location` que muestra el mapeo de un índice lógico hacia un `bloque` y un `offset`. | Versión que revela la ecuación para enrutar datos en la cuadrícula dinámica. | Muestra cómo esta técnica reduce dramáticamente el desperdicio de memoria en comparación con duplicar un arreglo grande. |
   | `demo_deng_vector.cpp` | La impresión simultánea en el bucle donde `size` crece de 1 en 1, pero `capacity` crece a saltos. | Separación entre los elementos lógicos en uso. | Es la prueba de cómo se distribuyen los costos de realojamiento para lograr un tiempo amortizado de `O(1)` al final del arreglo. |
   | `demo_stl_vector_contraste.cpp` | Misma progresión escalonada de `size` vs `capacity`. | Actúa como un grupo de control basado en el estándar `std::vector` | Valida que las implementaciones propias emulan correctamente las estrategias de eficiencia. |

1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?

   * **Arreglo**: Se instancia indicando un tamaño inicial explícito. El acceso y para modificar elementos se utiliza el operador `[]`.
   * **Longitud**: Es un atributo directamente accesible a través de `.length`
   * **Asignación**: Cuando haces `b = a`, el objeto `b` asume el control del bloque de memoria de `a`. Asi la longitud y el contenido de `b` pasan `a` ser los que tenía `a`, descartando el arreglo que `b` tenía en un inicio.

2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?

   * Las operaciones `add(1, 15)` y `remove(i)` tienen un costo `O(n-i)` directamente proporcional a la cantidad de elementos que se deben mover.

3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?

   * Se abandonan los bucles `for` iterativos que desplazan los elementos uno por uno.

4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?

   * El mejor ejemplo son las llamadas a la función `print_location` en el main (para los índices 0, 2 y 5).
   Muestra cómo un índice lógico se traduce en coordenadas de memoria reales (el número de bloque y su posición exacta offset dentro de ese bloque).

5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?

   * La impresión simultánea de `size` y `capacity` dentro del primer bucle `for`. Permite ver cómo el tamaño crece linealmente de 1 en 1 con cada inserción, mientras que la capacidad se mantiene estática hasta que se llena y luego da saltos duplicándose.

6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?

   * Ejecutan un bucle de inserciones donde se imprimen simultáneamente `size` y `capacity` paso a paso.

7. ¿Qué demo sirve mejor para defender amortización y cuál sirve mejor para defender uso de espacio?

   * Para defender amortización `demo_deng_vector.cpp` es la mejor porque expone el truco detrás del tiempo amortizado `O(1)` para las inserciones al final de un arreglo dinámico.
   * Para defender uso de espacio `demo_rootisharraystack_explicado.cpp` es la mejor para explicar cómo minimizar el desperdicio de memoria.

#### Bloque 3 - Pruebas públicas, stress y correctitud

1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?

   * `add(x)`: Valida que se puedan añadir elementos al final de la estructura.
   * `add(i, x)`: Valida que la estructura pueda insertar un elemento en el medio y realizar los desplazamientos internos sin perder datos.
   * `size()`: Valida que el contador interno refleje correctamente la cantidad de elementos tras las inserciones y las eliminaciones.
   * `get(i)`: Valida que los elementos se encuentren exactamente en las posiciones esperadas.
   * `remove(i)`: Valida que se elimine el elemento en la posición dada cerrando el espacio dejado, y que la función retorne correctamente el valor del elemento recién eliminado

2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?

   * `add(i, x)`: Valida que puede crecer dinámicamente sin desplazar elementos existentes.
   * `size()`: Valida que el contador interno se actualice correctamente tras las inserciones y también se utiliza dinámicamente para calcular la posición final en las primeras inserciones.
   * `get(i)`: Valida que el elemento insertado en el medio esté en la posición correcta.
   * `remove(i)`: Valida el peor caso posible de desplazamiento al eliminar el primer elemento.

3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?

   * `add(i, x)`: valida mediante un bucle `for` que inserta 6 elementos secuencialmente.
   * `size()`: Valida que el tamaño lógico total refleje correctamente el número de elementos tras la construcción inicial y tras eliminar elementos.
   * `get(i)`: Valida que la ecuación interna funcione, logrando localizar y leer un dato específico.
   * `set(i, x)`: Valida que se pueda sobreescribir correctamente el valor en una posición específica y que la función retorne exitosamente el valor antiguo que estaba en esa posición.
   * `remove(i)`: Valida que al quitar un elemento intermedio, la estructura devuelva el valor correcto y realice los desplazamientos hacia la izquierda.

4. ¿Qué sí demuestra una prueba pública sobre una estructura?

   * Una prueba pública demuestra fundamentalmente la corrección funcional de una estructura de datos.

5. ¿Qué no demuestra una prueba pública?

   * Una prueba pública no demuestra la complejidad asintotica de tiempo, complejidad de espacio, uso de memoria, etc. En otras palabras no demuestra la eficiencia de la estrucutura de datos. 

6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?

   * En `ArrayStack` se estresa el crecimiento y reducción de la cola al inserta 200 elementos y luego eliminando exactamente la mitad desde el final .
   * En `FastArrayStack` se estresa la reducción haciendodolo crecer hasta 200, y luego eliminando 50 elementos desde la cabeza usando `remove(0)`.
   * En `RootishArrayStack` se estresa el crecimiento y reducción de los arreglos independientes insertando 120 elementos obligando a la estructura a instanciar aproximadamente 15 bloques de memoria distintos y eliminar la mitad hasta el índice 60.
   * En `DengVector` se estresa el crecimiento, reducción y estabilidad al insertar 1000 elementos, usando remove(0) 700 veces y forzando a los 300 restantes a moverse hasta el principio del arreglo.

7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

   * Pasar las pruebas públicas demuestra que el código funciona en el momento de la prueba. Explicar los invariantes y la complejidad asintótica demuestra por qué funciona, que seguira funcionando pese al tiempo, y saber exactamente lo hace el código.

#### Bloque 4 - Vector como puente entre teoría y código

1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?

   * `_size`: Define la límite de los datos útiles. El arreglo termina en el índice `_size - 1`.
   * `_capacity`: Actúa como el límite físico antes de que la estructura se vea obligada a pedir más memoria.
   * `_elem`: Representa el arreglo subyacente en la memoria RAM.

2. ¿Cuándo debe ejecutarse `expand()`?

   * Debe ejecutarse en el momento que el arreglo se queda sin espacio físico libre.

3. ¿Por qué `insert(r, e)` necesita desplazar elementos?

   * Al ejecutar `insert(r, e)`, le estás diciendo a la estructura que coloque el nuevo elemento `e` exactamente en el índice `r`. Y al nopoder sobreescribir y deber preservar la continuidad desplaza los elementos.

4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?

   * `remove(r)` elimina un único elemento que se encuentra exactamente en el índice `r` mientras que `remove(lo, hi)` elimina un bloque continuo de múltiples elementos a la vez.

5. ¿Qué evidencia de copia profunda aparece en la demo?

   * En `demo_deng_vector.cpp` se le suma 1 a todos los elementos del objeto copia, y luego multiplica por 2 todos los elementos del objeto asignado. Al imprimir los resultados en consola después de estas operaciones, los valores son completamente distintos. El poder mutar independientemente sin afectarse mutuamente demuestra que se realizó una copia profunda.

6. ¿Por qué `traverse()` es una buena interfaz didáctica?

   * Porque `traverse()` separa el cómo recorrer el arreglo del qué hacer con los datos.

7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?

   * Implementar un vector fuerza a gestionar explícitamente la propiedad y liberación de los recursos mediante copias profundas y destructores, en lugar de dar la memoria por sentada.

#### Bloque 5 - RootishArrayStack: espacio y mapeo

1. ¿Cómo se distribuyen los elementos entre bloques?

   * los elementos se distribuyen en una serie de arreglos independientes cuyos tamaños crecen en progresión aritmética.

2. ¿Por qué con `r` bloques la capacidad total es `r(r+1)/2`?

   * Dado que los bloques crecen en progresión (1, 2, 3, 4, ...), la cantidad total de elementos que puede almacenar la estructura cuando tiene `r` bloques equivale a la suma de los primeros `r` números enteros es decir la Suma de Gauss.

3. ¿Qué problema resuelve `i2b(i)`?

   * `i2b(i)` utiliza la fórmula cuadrática para determinar en qué bloque cae el índice `i` sin usar bucles en un tiempo `O(1)`.

4. ¿Qué información produce `locate(i)` en la versión explicada?

   * `locate(i)` encapsula la matemática de enrutamiento del `RootishArrayStack`. Traduce la abstracción lineal del usuario a la realidad fragmentada de la memoria. Esta encapsulación es la que permite que `get(i)` y `set(i, x)` operen con tan solo un par de variables desempaquetadas.

5. ¿Qué se gana en espacio frente a `ArrayStack`?

   * Se gana una altísima eficiencia de espacio sin renunciar al tiempo amortizado `O(1)` de inserción,

6. ¿Qué se conserva igual respecto a la interfaz?

   * Las operaciones que se conservan son:
      * `size()`: Sigue devolviendo la cantidad total de elementos lógicos que el usuario ha insertado.
      * `get(i)` y `set(i, x)`: El usuario sigue pidiendo o modificando datos utilizando un simple índice lineal (de 0 a n-1).
      * `add(i, x)` y `remove(i)`: El usuario sigue asumiendo que al insertar en el medio se "deja un espacio" y al eliminar se "llena el esapcio", desplazando los elementos a la derecha o a la izquierda de forma continua.

7. ¿Qué parte les parece más difícil de defender oralmente: el mapeo, el análisis espacial o el costo amortizado de `grow/shrink`?

   * `grow/shrink` lo considero lo más dificil de defender oralmente, el cómo cada inserción paga su propio costo `O(1)`.

#### Bloque 6 - Refuerzo de lectura (Lectura4-Deng)

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

