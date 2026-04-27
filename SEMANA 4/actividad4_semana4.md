## Actividad 4-CC232

### Estudiante

   * Alvinagorta Huapaya Angel Andres 

#### Bloque 1

1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.

    * La diferencia se encuentra en el orden en el cual se ingresan y extraen los elementos.

2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".

    * Un `Stack` funciona bajo su diseño LIFO, al hacer un `.push()` se detiene un estado y apilas uno nuevo, y como el `Stack`solo te da acceso al `.top()` se fuerza a resolver y retirar `.pop()` siendo este "lo último pendiente".

3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.

    * Un `Queue` funciona bajo el diseño FIFO, al hacer un `.push()` se agrega un nuevo elemento al final de la fila, y como el `Queue` solo te da acceso al `.front()` se fuerza a atender y retirar con `.pop()` siendo este "el primero que estaba en espera".

4. Explica qué significa reemplazar recursión implícita por una estructura explícita.


5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.


6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?


7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.


8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.


9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.


10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.


11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.


12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".



#### Bloque 2 (tabla y respuestas)

1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?

    * La parte de la salida que deja más clara la diferencia son estas dos líneas:
    ```
    Tope de la pila = 9      //acceso directo al último elemento ingresado
    Frente de la cola = 10   //acceso directo al primer elemento que ingresado
    ```

2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?

    * El observable que nos `permite afirmarlo es la salida obtenida en el terminal
    ```
    12345 en base 8 (recursivo) = 30071
    12345 en base 8 (iterativo) = 30071
    ```
    si las versiones recursiva e iterativa son equivalentes, ambas sentencias mostrarán lo mismo.

#### Bloque 3 (respuestas)
#### Bloque 4 (respuestas y experimentos 1-2)
#### Bloque 5 (respuestas y experimento 3)
#### Bloque 6 (respuestas y experimentos 4-5)
#### Bloque 7 (respuestas y experimento 6)
#### Bloque 8 (respuesta final)