## Actividad 3-CC232

### Integrante

   * Alvinagorta Huapaya Angel Andres

#### Bloque 1

1. Explique con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.

    * Cuando se pasa de almacenamiento contiguo a dinámico, cambia la facilidad de acceso de rápida a lenta y la facilidad de modificar de lenta a rápida.

2. Explique la diferencia entre acceso por rango y acceso por posición o enlace.

    * En el acceso por rango para acceder a un elemento se usa un indice (0, 1, 2, ... n-1), se suele usar en arrays y vectores, mientras que en el acceso por posición o enlace para acceder a un elemento se usa punteros de nodo a nodo, se suele usar en SLList y DLList.

3. Explique por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.

    * Esto es debido a que presenta la ventaja de no ser necesario organizar ni desplazar elementos, solo cambiar enlaces. Pero si se busca acceder por índice el costo total es `O(n)`.

4. Explique por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.

    * `SLList` es una estructura dual que puede usarse como `Stack` o `Queue` con complejidad `O(1)` para todas las operaciones principales.

5. Explique por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.

    * `SLList` no implementa naturalmente todas las operaciones `Deque` porque requiere acceso bidireccional, para lo cual necesita de un `DLList`.

6. Explique qué aporta el nodo centinela `dummy` en `DLList`.

    * El nodo `dummy` actúa como un puente entre el final y el principio de la lista, convirtiéndola en una lista circular. Por lo que todo nodo real siempre tiene un nodo anterior y un nodo siguiente.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

    * Ya que las 4 operaciones llaman a `getNode(i)`, la eficiencia de `DLList` recae en cómo este método busca el elemento y dado que elige el camino más corto, el número máximo de iteraciones que realiza el bucle es siempre el menor entre `i` y `n-i`, justificando así el costo en `O(1 + min(i, n-i))`.

8. Explique cuál es la idea espacial central de `SEList`.

    * La idea espacial central es resolver el problema de desperdicio de memoria causado por los punteros en las listas `DLList`.

9. Explique por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

    * `SEList` necesita mover elementos constantemente desde el final de un bloque hacia el principio del siguiente para equilibrarse, al reutiliza una `BDeque` basada en `ArrayDeque`, se sobrescribe y anula el método `resize()`. Esto garantiza que los bloques mantengan un tamaño físico fijo y cumplan la eficiencia espacial de `SEList`.

10. Explique qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

    * `DengList` y las estructuras de Morin no se reemplazan porque no hacen lo mismo ya que la única función de `DengList` es tener un objeto interno (`legacy_type impl_`) y pasar todas las peticiones hacia él.

#### Bloque 2

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|---|---|---|---|
| `demo_sllist.cpp` | Se agregan números al inicio y al final  de la misma lista | Una lista con un solo enlace puede actuar como pila y cola simultáneamente | Acceso O(1) en ambos extremos por tener dos punteros: cabeza y cola |
| `demo_dllist.cpp` | Se insertan números en posiciones específicas del medio de la lista | Lista con enlaces hacia adelante y atrás permite buscar desde ambos extremos | Se busca el camino más corto: O(1 + min(posición, n-posición)) |
| `demo_selist.cpp` | Los elementos mantienen orden lógico aunque están organizados internamente en bloques | Divide la lista en bloques para ahorrar memoria desperdiciada en punteros | Usa menos memoria que una lista doblemente enlazada sin perder eficiencia O(1) en operaciones |
| `demo_deng_list.cpp` | La lista se ordena automáticamente con `.sort()` | Una lista reforzada que envuelve otra lista y le añade capacidades nuevas | No duplica código, solo reutiliza algoritmos ya existentes sobre la estructura original |
| `demo_morin_deng_bridge.cpp` | Datos ordenados y duplicados removidos sin alterar la lista base | Algoritmos trabajan sobre una lista sin modificar su código interno | Los algoritmos se escriben una sola vez y funcionan en diferentes estructuras |
| `demo_min_structures.cpp` | Se reporta rápidamente el valor mínimo en la estructura | Se almacena información extra junto con los datos normales | Optimiza búsquedas sin cambiar cómo funciona la estructura principal |
| `demo_linked_adapters.cpp` | Se usan restricciones (pila, cola, deque) sobre la misma estructura de lista | Adapta una lista flexible limitando sus operaciones para un comportamiento específico | Reutiliza la lista sin reescribir: solo controla qué operaciones se permiten |
| `demo_contiguous_vs_linked.cpp` | Comparación de velocidad en acceso, inserción local y cómo usa memoria | Contrasta almacenamiento contiguo contra almacenamiento enlazado | Array es rápido en acceso pero lento en inserción; Lista es lenta en acceso pero rápida en inserción |
| `demo_xor_list.cpp` | Una lista usa un solo puntero tipo XOR por nodo en lugar de dos | Optimiza memoria combinando dos direcciones en un solo valor XOR | Ahorra memoria con el costo de complejidad en el código |
| `demo_capitulo3_panorama.cpp` | Resumen visual de todas las estructuras de listas vistas en el capítulo | Muestra cómo cada estructura resuelve un problema diferente con ventajas propias | Cada estructura es mejor en un contexto: velocidad de acceso vs. velocidad de inserción vs. uso de memoria |

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?
    * La secuencia que deja más clara la coexistencia de comportamiento es:
    ```
    q.add(10);
    q.add(20);
    q.push(5);

    std::cout << "peek = " << q.peek() << "\n";
    std::cout << "pop = " << q.pop() << "\n";
    std::cout << "remove = " << q.remove() << "\n";
    ```
    Donde observamos que add(10) y add(20) agregan al final como cola (FIFO) y push(5) inserta en la cabeza (LIFO). 

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?

    * La operación más clara es:
    ```
    d.add(1, 20);
    ```
    Muestra que `DLList::add(i, x)` puede insertar en cualquier índice válido, no solo al inicio o al final.

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?

    * El observable clave es:
    ```
    for (int i = 0; i < s.size(); ++i) {
    std::cout << s.get(i) << ' ';
    }
    ```
    Muestra que aunque internamente `SEList` divide los elementos en bloques, se sigue observando una lista ordenada por posición lógica 0, 10, 20, ..., esto defiende que mantiene el orden lógico.

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?

    * Que la lista reforzada por Deng pueda ordenarse a sí misma mediante una simple llamada a `.sort()` muestra que posee herramientas algorítmicas listas para usar, ocultando la complejidad de usar un algoritmo de ordenamiento sobre nodos enlazados como lo haria un ADT de lista completo.

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?

    * La salida esperada:
    ```
    DLList reforzada con Deng: 1 2 3 4 
    Removido = 1
    ```
    El que los datos esten ordenados y que se reporte haber eliminado el elemento duplicado, prueba que los algoritmos se ejecutaron con éxito. Manteniendo la clase `ods::DLList` intacta.

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?

    * Almacenar valores define la identidad y el comportamiento de la estructura, mientras almacenar información adicional para `min()` no cambia en absoluto cómo se comporta la estructura y su único propósito es la optimización algorítmica.

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?

    * El que mejor representa el concepto de reutilizar una estructura base para ofrecer una interfaz nueva es el `LinkedStack`. Esto debido a que restringe la libertad de la estructura base para forzar un comportamiento estrictamente LIFO.

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

    | Caractersiticas | Contiguo (`ArrayDeque`) | Enlazado (`DLList`) |
    |---|---|---|
    | Acceso por índice | Requiere una simple operación matematica | Requiere saltar nodo por nodo |
    | Inserción local | Requiere desplazar otros datos | Solo cambia punteros |
    | Localidad de memoria | Aprovecha la caché de la CPU | Nodos fragmentados en el Heap |

#### Bloque 3

1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?

    * La prueba pública para `SLList` valida las siguientes operaciones mínimas:
        * `add(value)`: Inserta un elemento al final de la lista.
        * `push(value)`: Inserta un elemento al frente de la lista.
        * `size()`: Devuelve el número de elementos en la lista.
        * `peek()`: Devuelve el valor del elemento en el frente sin removerlo.
        * `pop()`: Remueve y devuelve el elemento del frente.
        * `remove()`: Remueve y devuelve el elemento del final.

2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?

    * La prueba pública para `DLList` valida las siguientes operaciones mínimas:
        * `add(i, value)`: Inserta un elemento en la posición i.
        * `size()`: Devuelve el número de elementos en la lista.
        * `get(i)`: Devuelve el valor del elemento en la posición i.
        * `remove(i)`: Remueve y devuelve el elemento en la posición i.

3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?

    * La prueba pública para `SEList` valida las siguientes operaciones mínimas:
        * `add(i, value)`: Inserta un elemento en la posición i.
        * `size()`: Devuelve el número de elementos en la lista.
        * `get(i)`: Devuelve el valor del elemento en la posición i.
        * `set(i, value)`: Establece un nuevo valor en la posición i y devuelve el valor anterior.
        * `remove(i)`: Remueve y devuelve el elemento en la posición i.

4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?

    * En `SLList`:
        * `secondLast()`: Recupera el valor del penúltimo nodo.
        * `reverse()`: Invierte el sentido de los punteros `next` de todos los nodos de la lista asi el último pasa a ser el primero.
        * `checkSize()`: Recorre la lista contando los nodos uno por uno para asegurar que el contador de tamaño no se desincronice después de las modificaciones.

    * En `DLList`:
        * `rotate(int r)`: Desplaza circularmente los elementos de la lista.
        * `isPalindrome()`: Verifica si el contenido de la lista es simétrico.
        * `checkSize()`: Verifica que la cantidad de elementos sea correcta y que los enlaces entre nodos `next` y `prev` estén conectados correctamente.

    * En `MinStack`, `MinQueue`, `MinDeque`:
        * `min()`: Prueba que las estructuras son capaces de rastrear y devolver correctamente el valor mínimo actual en todo momento.
    
5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?

    * Valida que `LinkedStack`, `LinkedQueue` y `LinkedDeque` respeten estrictamente sus invariantes y que gestionen de manera correcta su tamaño y límites.

6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?

    * **Integración**: Las estructuras base mantienen su función de gestionar la memoria y los enlaces físicos por lo que no se altera el diseño de las clases originales.
    * **Reutilización**: El algoritmo de ordenamiento se escribió una vez en la capa `cc232`. Debido a esto el algoritmo puede operar sobre cualquier estructura que cumpla con tener `get`, `set` y `size`.

7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?

    * **Crecimiento**:
        * Usar `add(10)` y `push(5)`, se estresa la lógica de los punteros `head` y `tail` para asegurar que ambos extremos se actualicen correctamente.
        * Al hacer `add(1, 20)` entre el 10 y el 30, obliga a la lista a reconectar cuatro punteros simultáneamente sin perder la cadena.
    * **Borrado**:
        * Usar `pop()` y `remove()` prueba la extracción desde la cabeza de la lista, lo que requiere mover el puntero principal y liberar el nodo viejo.
        * Extraer el elemento del medio `remove(1)` obliga a los nodos vecinos (0 y 2) a saltarse el nodo eliminado y apuntarse mutuamente.
    * **Mantenimiento del tamaño lógico**:
        * Intenta estresar que el contador interno `n` sume exactamente 1 en cada `add`/`push` y reste exactamente 1 en cada `remove`/`pop`.

8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?

    * Demuestra que la estructura se comporta según las reglas matemáticas del ADT que representa.

9. ¿Qué no demuestra una prueba pública por sí sola?

    * Una prueba pública estándar no demuestra la eficiencia del ADT.

10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?

    * Pasar las pruebas públicas demuestra que el código funciona en el momento de la prueba, explicar las invariantes, punteros y complejidad significa que el ADT está bien diseñado y seguira funcionando pese al tiempo.

#### Bloque 4

1. En `SLList`, ¿qué papel cumplen `head`, `tail` y `n`?

    * `head`: Es la única forma de entrar a la lista.
    * `tail`: Es una optimización para evitar el viaje para añadir un elemento al final y tener que empezar en head y saltar nodo por nodo hasta encontrar el último.
    * `n`: Actúa como una caché del tamaño.

2. En `SLList::push`, `pop`, `add` y `remove`, ¿qué punteros cambian exactamente?

    * En `push(x)`:
        * `u->next`: Se actualiza para apuntar al antiguo `head`.
        * `head`: Cambia para apuntar al nuevo nodo `u`.
        * `tail`: Si n es 0 antes de insertar, `tail` también se actualiza para apuntar a `u`.
    * En `pop` y `remove`:
        * `head`: Cambia para apuntar al segundo nodo de la lista.
        * `tail`: Cambia a `nullptr` si al eliminar el nodo el tamaño `n` llega a 0.
    * En `add`:
        * `tail`: Se actualiza para apuntar al nuevo nodo `u`.

3. Explica cómo funciona `secondLast()` y por qué no puede resolverse directamente con solo mirar `tail`.

    * El puntero `tail` te da acceso inmediato al último nodo de la lista, pero en una `SLList` los nodos solo tienen un puntero `next` por lo que no es posible dar un paso hacia atras. 
    * Ante la imposibilidad de ir de atrás hacia adelante, la única solución es `secondLast()` que recorre la lista desde el principio hasta encontrar el nodo deseado.

4. Explica paso a paso cómo funciona `reverse()` y por qué no necesita estructura auxiliar.

    * Los pasos son:
        ```
        while (curr != nullptr) {
        // Paso 1: Guardamos el resto de la lista antes de romper el enlace
        Node* next = curr->next;
        // Paso 2: El nodo actual deja de apuntar hacia adelante y pasa a apuntar hacia atrás
        curr->next = prev;
        // Paso 3: Movemos 'prev' al nodo actual para que el siguiente nodo lo use
        prev = curr;
        // Paso 4: Movemos 'curr' al nodo que habíamos guardado en el paso 1 para continuar
        curr = next;
        }
        ```
    * No necesita de una estructura auxiliar porque opera **in-place** (transforma la entrada de datos modificándola directamente en su ubicación original en memoria, sin requerir espacio auxiliar significativo para funcionar)

5. Explica qué verifica `checkSize()` y por qué esta función ayuda a defender correctitud.

    * `checkSize()` recorre físicamente la lista saltando de `next` en `next` y cuenta cuántos nodos existen en la memoria y verifica que este conteo coincida con la caché `n`.y ayuda a defender correctitud porque garantiza que ninguna operación compleja haya roto los enlaces internos, pudiendo detectar cualquier desincronización de punteros al instante. 

6. En `DLList`, explica por qué `getNode(i)` puede empezar desde el inicio o desde el final.

    * En `DLList` cada nodo tiene un puntero `prev` y la lista está conectada de forma circular mediante el nodo `dummy`, lo que permite viajar hacia atrás empezando desde la cola, ademas que elige la ruta más corta y en el peor de los casos solo recorrerá la mitad de la lista.

7. En `DLList::addBefore`, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?

    * Se configuran los punteros `prev` y `next` del nuevo nodo. Luego, se actualiza el `next` del nodo anterior y el `prev` del nodo siguiente para que ambos apunten hacia el recién llegado. Y elimina los casos borde porque garantiza que no existan punteros nulos.

8. Explica cómo funciona `rotate(r)` sin mover los datos elemento por elemento.

    * `rotate(r)` en lugar de mover los datos uno por uno, modifica la estructura de la cadena reconectando únicamente 6 punteros.

9. Explica cómo `isPalindrome()` aprovecha la naturaleza doblemente enlazada de la estructura.

    * `isPalindrome()` aprovecha los punteros `prev` y `next` para usar dos rastreadores, uno que va hacia adelante y otro al que retrocede. Ambos convergen hacia el centro comparando los valores, lo que verifica la simetría de la lista en una sola pasada sin usar memoria extra.

10. En `SEList`, explica qué representa `Location`.

    * `SEList` usa diseño en bloques y para buscar o modificar un elemento de la lista global se necesita dos coordenadas de lo que se encarga `Location`. Por ello `Location` representa la ubicación física y exacta de un elemento dentro de la lista.

11. Explica qué hacen `spread()` y `gather()` y en qué situaciones aparecen.

    * `spread()` toma un grupo de `b` nodos consecutivos que están al máximo de capacidad y agrega un nuevo nodo vacío al final del grupo. Para eso desplaza los elementos un espacio hacia la derecha de manera escalonada para liberar espacio en el nodo original `u`.
    * `gather()` toma un grupo de `b` nodos que están casi vacíos y compacta sus elementos hacia la izquierda. Al empujar todos los datos hacia los primeros `b - 1` nodos del grupo, el último nodo queda vacío, se elimina y se libera la memoria.

12. Explica cómo el tamaño de bloque `b` afecta el trade-off entre acceso, actualización y uso de espacio.

    * **Acceso**: Un `b` grande mejora el tiempo de acceso.
    * **Actualización**: Un `b` pequeño hace que las inserciones y eliminaciones locales sean más rápidas.
    * **Uso de espacio**: Si `b` es pequeño se usa mucha memoria y si `b` es grande hay memoria reservada que no se utiliza.

#### Bloque 5

1. ¿Cómo reutiliza `LinkedStack` a `SLList`?

    * push(x) delegada a list.push(x), que cuando se inserte un elemento en la pila, este se inserta en el head de la SLList.
    * pop() delegada a list.pop(), que cuando se saque un elemento de la pila, este se elimina del head de la SLList.
    * top() delegada a list.peek()`devolver el valor que está en la cabeza de la `SLList sin removerlo.

2. ¿Cómo reutiliza `LinkedQueue` a `SLList`?

    * `add(x)` delega a `list.add(x)`, que inserta el nuevo elemento directamente al final de la lista.
    * `remove()` delega a `list.remove()`, que elimina y devuelve el elemento que está al inicio de la lista.
    * `front()` delega a `list.peek()`, permitiendo ver el valor en el `head` sin modificar la cola.

3. ¿Por qué `LinkedDeque` se construye naturalmente sobre `DLList` y no sobre `SLList`?

    * `LinkedDeque` puede insertar y eliminar elementos en ambos extremos en tiempo constante constante, lo que se dificulta con `SLList` ya que sus nodos solo apuntan hacia adelante, por lo que recorre toda la lista desde el principio para encontrar el penúltimo nodo y esto toma un tiempo lineal. 

4. En `MinStack`, ¿por qué cada entrada guarda el valor y el mínimo acumulado?

    * Se debe a que se guarda el mínimo acumulado junto con cada valor para que la operación `min()` siempre responda de forma instantánea con tiempo constante `O(1)`. 

5. En `MinQueue`, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?

    * Se usan dos pilas porque simulan una cola, y permiten aprovechar la habilidad que tienen las pilas para recordar mínimos históricos sin tener que recalcular nada.

6. En `MinDeque`, ¿qué problema resuelve el rebalanceo entre `front_` y `back_`?

    * `rebalance()` actua cuando una pila se queda vacía y toma todos los elementos globales y los reparte una mitad a `front_` y la otra a `back_`, teniendo un rendimiento de `O(1)` amortizado. 

7. Compara "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.

    | Criterio | Implementación (`SEList`, `DLList`) | Adaptación (`LinkedStack`, `MinQueue`) |
    |---|---|---|
    | Gestión de Memoria | uso de punteros `new`,`delete` | delegada a la clase base |
    | Velocidad de Escritura | Lenta (requiere algoritmos complejos) | Rápida (solo mapeo de funciones) |
    | Riesgo de bugs | Alto (fugas de memoria) | Bajo (reutiliza código ya probado) | 

8. ¿Qué operaciones puedes defender como constantes y cuáles debes defender como amortizadas?

    * Constantes:
        * LinkedStack: push(), pop(), top()
        * LinkedQueue: add(), remove(), front()
    * Amortizadas:
        * MinQueue: add() y remove()
        * MinDeque: addFront(), addBack(), removeFront(), removeBack()

#### Bloque 6

1. ¿Qué operaciones del ADT de lista aparecen reforzadas en `DengList`?

    * Operaciones como `sort()` para ordenar la lista, `reverse()` para invertirla, y `uniquify()` para eliminar duplicados. Estas operaciones no existían originalmente pero se agregan sin cambiar la estructura interna de `DLList` o `SEList`.

2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?

    * Permite agregar funcionalidades sin tocar el código ya probado de las estructuras base. Esto evita introducir bugs en código que ya funciona y permite reutilizar las mismas bases con diferentes niveles de sofisticación.

3. Explica qué hacen `to_deng` y `assign_from_deng`.

    * `to_deng` convierte datos de una estructura base (`DLList` o `SEList`) hacia una `DengList` para que puedan usarse los algoritmos reforzados. `assign_from_deng` hace lo inverso: toma los datos procesados de `DengList` y los devuelve a la estructura original.

4. Explica por qué `stable_sort_with_deng` no obliga a reimplementar ordenamiento dentro de `DLList` o `SEList`.

    * Porque el algoritmo de ordenamiento vive en `DengList`, una capa separada. `stable_sort_with_deng` convierte los datos hacia `DengList`, ordena ahí, y devuelve el resultado. Las estructuras base solo actúan como contenedores sin necesidad de entender el algoritmo.

5. Explica qué hace `dedup_with_deng` y qué relación guarda con `deduplicate()` o `uniquify()` de la teoría.

    * `dedup_with_deng` elimina elementos duplicados de la lista. Esto es exactamente lo que hace `deduplicate()` o `uniquify()` en la teoría de estructuras de datos, pero ahora implementado como un algoritmo externo sobre la interfaz común de `DengList`.

6. Explica por qué `reverse_with_deng` es un ejemplo de reutilización de algoritmos sobre una interfaz común.

    * Porque `reverse_with_deng` usa las mismas operaciones básicas que cualquier lista define. Al depender solo de esta interfaz común, el mismo algoritmo funciona con `DLList`, `SEList` o cualquier otra lista que implemente estas operaciones.

7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?

    * Convertir datos entre estructuras cuesta tiempo y memoria (copiar todos los elementos). Vale la pena cuando necesitas usar algoritmos complejos que solo existen en `DengList`, especialmente para operaciones puntuales. No vale la pena si necesitas hacer conversiones constantemente.

#### Bloque 7

1. Compara `ArrayDeque` y `LinkedDeque`: ¿qué cambia en representación y qué cambia en costo observable?

    * **Representación**: `ArrayDeque` guarda todo junto en un solo bloque de memoria y `LinkedDeque` guarda los datos separados en nodos esparcidos por la memoria unidos por punteros.
    * **Costos observables**:
        * Para buscar: `ArrayDeque` llega directo al dato en tiempo estricto `O(1)`, mientras que `LinkedDeque` en `O(n)` al saltar de nodo en nodo.
        * Para modificar los extremos: `LinkedDeque` es instantáneo y estable `O(1)`, y `ArrayDeque` es rápido, pero sufre pausas para copiar datos y hacer más grande su arreglo. 

2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?

    * Significa que los elementos están físicamente pegados unos junto a otros. Asi cuando el procesador necesite leer un dato, no trae solo ese elemento, sino que carga un "bloque" contiguo entero hacia su memoria caché. 

3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?

    * Las operaciones que más favorecen son las inserciones y eliminaciones, ya que en en los extremos son instantáneas. Y en posiciones intermedias solo requieren reconectar un par de punteros locales. 

4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?

    * **Acceso aleatorio**: Comparar `t_array_random_get` y `t_linked_random_get`, expondrá a `DLList` que debe recorrer los nodos secuencialmente, frente al acceso instantáneo de `ArrayDeque`.
    * **Operaciones externas**: Comparar `t_array_deque_ends` y `t_linked_deque_ends`, demuestran que al operar exclusivamente en las puntas, ambas estructuras son altamente eficientes. 

5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?

    * Esto es debido a que un benchmark mide un escenario aislado, no la realidad universal. En la realidad las aplicaciones mezclan lecturas, escrituras y borrados de forma caótica, lo que cambia completamente el rendimiento.

6. ¿Qué idea intenta mostrar `XorList` respecto al ahorro de punteros?

    * `XorList` muestra cómo lograr la funcionalidad bidireccional de `DLList` usando la memoria de `SLList`. En lugar de almacenar dos punteros separados en cada nodo, `XorList` almacena un solo campo `link`. 

7. ¿Qué desventaja práctica introduce una estructura como `XorList` aunque sea interesante desde el punto de vista del espacio?

    * En una `DLList` normal, si se tiene la referencia a un nodo en el medio, se puede mover hacia adelante o hacia atrás libremente. En una `XorList`, se necesita conocer la dirección del nodo anterior para poder decodificar y calcular el siguiente. 

#### Bloque 8

Responde esta pregunta final:

1.  ¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

    * Cambiamos una representación contigua por una representación enlazada, el acceso por posición exacta `i` deja de ser un cálculo matemático instantáneo `O(1)` y se vuelve lineal `O(n)` al tener que saltar de nodo en nodo. Ademas insertar o eliminar en el medio hay que mover muchos de los elementos siguientes una posición, y eso consume bastante tiempo.`SLList` logra `O(1)` al inicio pero sufre `O(n)` al borrar al final, `DLList` invierte en un puntero extra para garantizar `O(1)` simétrico en ambos extremos, y `SEList` balancea el costo de búsqueda y el gasto de memoria, logrando una eficiencia optimizada de `O(n/b + b)`.
    Ademas que se reutilizan las estrucuturas `SLList` y `DLListlas` envolviéndolas en clases adaptadoras como `LinkedStack` o `LinkedQueue`.

#### Autoevaluación breve

- **Qué podemos defender con seguridad:**
    * El comportamiento dual de `SLList` como Stack y Queue, y por qué los punteros `head`, `tail` y `n` son suficientes para garantizar `O(1)` en operaciones de extremos.
    * Cómo `DLList` aprovecha el nodo centinela `dummy` circular para eliminar casos borde y garantizar `O(1 + min(i, n-i))` en búsquedas.
    * La idea de `SEList` de balancear eficiencia de búsqueda y desperdicio de memoria mediante bloques de tamaño fijo `b`.

- **Qué todavía confundimos:**
    * El análisis de amortización en `MinDeque` podría ser más riguroso. La respuesta menciona `rebalance()` pero no explica con claridad por qué distribuir elementos a mitad y mitad garantiza amortización verdaderamente.
    * La operación `rotate(r)` en `DLList` se explica que modifica 6 punteros, pero faltaría detallar cuáles exactamente.

- **Qué evidencia usaríamos en una sustentación:**
    * **Demos ejecutándose correctamente**: `demo_sllist.cpp` mostrando coexistencia push/add, `demo_dllist.cpp` con inserciones intermedias, `demo_deng_list.cpp` llamando a `.sort()`.
    * **Tests pasando**: `test_public_extras.cpp` validando `reverse()`, `secondLast()`, `checkSize()` en todas las estructuras.
    * **Benchmark comparativo**: Gráficas mostrando `t_array_random_get` vs `t_linked_random_get` para demostrar acceso lineal vs constante.