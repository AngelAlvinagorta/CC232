### Integrantes - Grupo 2

* Alvinagorta Huapaya Angel Andres
* Magno Muro Renzo Jesús

### Bloque 1 - Respuestas

1. Expliquen con sus palabras la diferencia entre **problema**, **algoritmo**, **ADT** e **implementación**.

    * **Problema**: Es la tarea a resolver solo define las entradas (la situación inicial) y salidas (el resultado deseado).
    Ejemplo: Quiero ordenar un arreglo {5, 1, 4, 2, 8, 3} de menor a mayor.
    * **Algoritmo**: Los pasos lógicos para llegar a la solución.
    Ejemplo: Comparar los numeros en pares y ordenarlos. Este ejemplo en el caso queramos usar el método de ordenamiento de la burbuja. 
    * **ADT**: El modelo teorico que define el conjunto de datos y las operaciones que haremos con estos, sin ser necesario saber como se gestiona la memoria. 
    Ejemplo: Usaremos una lista indexada donde debemos almacenar elementos en un orden secuencial intercambiandolos en caso esten desordenados.
    * **Implementación**: Es el codigo que terminamos compilando y ejecutando. Siendo la representación de las ideas previas
    Ejemplo: El codigo `bubble_sort.cpp`.

2. En `bubble_sort.cpp`, expliquen qué observable conecta correctitud y costo.

    * Se conectan mediante:
        1. `changed` que indica si hubo al menos un intercambio en la pasada actual y al ser falso indica que no hay desorden local y evita pasadas innecesarias.
        2. `lastSwapIndex` que registra la posición del último intercambio de cada pasada garantizando el orden y mejorando a su vez el costo.

3. En `power.cpp`, expliquen por qué `power` mejora la idea de una versión ingenua.

    * Es debido a que `powerBF` (la versión ingenua) para hallar 3^5 lo hace calculando 3x3x3x3x3 el cual presenta costo `O(n)`, en cambio `power` para hallar 3^5 lo hace calculando 3x(3^2)^((5-1)/2) el cual presenta un costo de `O(logn)`, el cual es mucho menor conforme el exponente aumenta.

4. En `fibonacci.cpp`, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.

    * Esto es debido a que fib(8) necesita de fib(7) y fib(6) pero para hallar fib(7) necesita a fib(6) y fib(5) asi sucesivamente lo cual no es pratico debido a su costo de O(2^n) y Fib entrega el mismo resultado sin colapsar y posee un costo de O(1).

5. En `count_ones.cpp`, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.

    * Esto es debido a que la relacion entre el tamaño y el valor es expresado por Tamaño(bits)=log2(valor)+1. Lo cual indica que el valor numerico crece mas rapido que el tamaño fisico.

6. En `demo_adt_secuencia.cpp`, expliquen por qué la misma interfaz puede convivir con representaciones distintas.

    * Tenemos a `FixedArraySequence` y `VectorSequence` ambas pueden convivir ya que las 2 heredan de `IntSequence` sus métodos (polimorfismo) ofreciendo la misma intefaz externa y ocultando los detalles internos.

### Bloque 2 - Respuestas
1. En `demo_bubblesort.cpp`, ¿qué salida sirve para defender costo y no solo resultado?

    * **comparaciones** = : Demuestra matemáticamente que la versión optimizada hizo menos trabajo.
    * **intercambios** = : Mide el costo de escritura en memoria.
    * **ultimo swap** = : Explica por qué se reduce el costo.

2. En `demo_power.cpp`, ¿qué comparación concreta muestra una mejora algorítmica?

    * Al probar con exponentes muy grandes `power` muestra un mejor desempeño que `powerBF`, al tener un coste de O(logn).

3. En `demo_fibonacci.cpp`, ¿qué crecimiento se vuelve defendible?

    * Fib debido a que entrega el mismo resultado sin colapsar con un costo de O(1).

4. En `demo_countones.cpp`, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?

    ```
    const unsigned int x = 0b101101001u;
    std::cout << "x = " << x << " = " << std::bitset<16>(x) << "\n";
    ```
    Este ejemplo muestra el valor decimal vs la representación de bits y hace evidente que 361 ocupa solo 9 bits.

### Bloque 3 - Respuestas

1. ¿Qué funciones o ideas están verificando las pruebas públicas?

    * `test_public_week1.cpp` verifica `sum.h` en sus variantes, `power.h` mejora algorítmica O(n) → O(log n), `Fib.h` correctitud vs eficiencia.
    * `test_public_week1_extra.cpp` verifica `bubble_sort.h` ordenamiento con estadisticas, `count_one.h` contar 1s en representación binaria, `max_algorithms.h` máximo con distintas estrategias, `reverse_utils.h` invertir y rotar arreglos, `gcd.h` máximo común divisor, `hanoi.h` Torres de Hanoi.

2. ¿Qué sí demuestra una prueba pública?

    * Demuestran que la función produce el resultado correcto

3. ¿Qué no demuestra una prueba pública?

    * No demuestran la eficiencia con la que logran el resultado.

4. Elijan **una** pregunta de `preguntas_semana1.md` y respóndanla bien.

    * ¿Qué es complejidad temporal?

        * Describe cómo cambia el tiempo de ejecución de un algoritmo conforme crece el tamaño de los datos de entrada.

5. Usen la rúbrica para autoevaluarse en:

   * comprensión conceptual, **en proceso**
   * sustentación de correctitud, **en proceso**
   * análisis de eficiencia, **en proceso**. 