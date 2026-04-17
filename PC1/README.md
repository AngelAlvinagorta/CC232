### Integrantes

- Alvinagorta Huapaya Angel Andres
- Magno Muro Renzo Jesús

### Problema Asignado

- Valid Parentheses (Parentesis Validos)

### Enlace al enunciado en LeetCode

https://leetcode.com/problems/valid-parentheses/description/

### Especificación breve del problema

- Se busca determinar si la cadena s es valida.
- Una cadena es valida si y solo si:
    1. Los paréntesis de apertura deben cerrarse con paréntesis del mismo tipo.
    2. Los paréntesis se deben cerrar en el orden correcto (el último en abrir debe ser el primero en cerrar).
    3. Cada paréntesis de cierre tiene un paréntesis de apertura correspondiente del mismo tipo.

### Entrada y salida

**Entrada (Input)**
- Una cadena de texto s (tipo string).
- La longitud de s cumple con 1 <= |s| <= 10^4
- s contiene únicamente los caracteres '(', ')', '{', '}', '[' y ']'

**Salida (Output)**
- Un valor booleano (true o false)

### Tamaño de entrada relevante

- El tamaño de la entrada (n), es la longitud de la cadena s.
- El algoritmo itera una vez sobre cada carácter de la cadena s por lo que las operaciones subyacentes dependen directamente de cuántos carácteres se deban procesar (n=s.length()).

### Descripción de la solución

- Para la solución del problema aprovecharemos la propiedad LIFO de la estructura de datos Stack (Pila). Esto debido a que los parentesis validos dictan que el último en abrirse debe ser el primero en cerrarse lo cual se alinea con el comportamiento de una pila.
- El algoritmo funciona mediante los siguientes pasos:
    1. **Inicicalización**: Se genera un objeto tipo Pila con una capacidad máxima igual a la longitud de la cadena de entrada (n).
    2. **Iteración**: Se recorre la cadena s de izquierda a derecha, analizando un paréntesis (c) a la vez.
    3. **Push (Apilamiento)**: Si c es un paréntesis de apertura '(', '{', '[', se inserta en el tope de la Pila.
    4. **Pop (Validación y desapilamiento)**: Si c es un paréntesis de cierre ')', '}', ']' se verfica si la Pila esta vacia en caso lo esté indica que carece de su paréntesis de apertura, por lo que la cadena es invalida. Y en caso no esté vacía se extrae el elemento en el tope de la Pila y se compara con c, si no forman una pareja valida la cadena es inválida.
    5. **Verificación**: Terminado de procesar toda la cadena si la Pila esta vacía, todos los paréntesis se cerraron correctamente y la cadena es válida. Y en caso aún contenga elementos, quedaron parentésis sin cerrar y la cadena es invalida.

### Justificación de determinismo y factibilidad

- **Determinismo**: El algoritmo propuesto es estrictamente determinista ya que para cualquier entrada especifica dada (la cadena s), el algoritmo nos dará siempre la misma salida (true o false) y pasara por la secuencia de estados internos.
- **Factibilidad**: La solución es altamente factible debido a que la restricción máxima de la entrada (n) es 10^4. Por lo cual la Pila a lo mucho requerira almacenar 10^4 caracteres y si consideramos que se ocupa 1 byte por carácter se requerirá como máximo 10KB de memoria la cual es una cantidad insignificante por lo que no hay riesgo de desboradmiento de meoria. Y respecto al tiempo dado que el algoritmo realiza una sola pasada sobre la cadena a lo mucho procesara 10^4 caracteres lo cual solo toma una fracción de milisegundos en una CPU actual.

### Argumento de finitud

- El núcleo del algoritmo es un único bucle for que itera sobre los caracteres de la cadena s. Y dado las restricciones el bucle se ejecutara como máximo 10^4 veces
- En el bucle se realizan operaciones booleanas if/else y se llama a los métodos push, pop, top, isEmpty. Todas estas operaciones se ejecutan en un tiempo constante O(1).
- No existe ciclos while que dependan de condiciones variables que pudieran crear bucles infinitos. Por lo que el proceso termina luego de un múero finito de pasos.

### Argumento de correctitud

- Para demostrar la correctitud del algoritmo utilizaremos el recurso de Invariante.
- Al inicio de la iteración i (donde se evalúa el carácter s[i]), la pila contiene todos los paréntesis de apertura del prefijo s[0...i-1] que aún no han sido cerrados, conservando el orden en que fueron abiertos (el útimo en abrir se encuentra en el tope de la pila).

### Invariante

- Antes de iniciar el bucle (i=0), el prefijo de la cadena procesada es vacío, por lo que no hay paréntesis sin cerrar. La pila se inicializa vacía cumpliendo asi el invariante.
- Suponiendo que el invariante se cumple al inicio de de iteración i. Tenemos que carácter c=s[i].Ocurren 2 casos principales:
    1. Si c es un paréntesis de apertura, se empuja la píla(push). Al ser un nuevo paréntesis abierto en el prefijo s[0...i], pasa a ser el último sin cerrar. El invariante se mantiene para la iteración i+1.
    2. Si c es un paréntesis de cierre y la pila esta vacía significa que no hay paréntesis de apertura pendientes en el prefijo anterior. Por lo que c es un cierre inválido y se retorna false. Y en caso la pila no esté vacía extraemos el tope de la pila(pop). Por el invariante el tope es el último paréntesis de apertura que faltaba por cerrar y si el tipo de c coincide con el tope, se anulan y el elemento sale del cojunto de no cerrados y se mantendria el invariante en la iteración i+1. Y si no coinciden sus tipos se retorna false.
- El bucle termina cuando i=n y según nuestra invariante la pila contiene ahora todos los paréntesis de paertura de la cadena completa que no fueron cerrados. Garantizando la correctitud.

### Complejidad temporal
- La complejidad temporal es O(n) donde n es la longitud de la cadena. El algoritmo recorre cada caracter exactamente una vez por bucle for. Dentro cada iteración se ejecutan las operaciones de pila las cuales son O(1). Por tanto T(n) es lineal.


### Complejidad Espacial
- La complejidad es O(n) donde es la longitud de la cadena. La solución reserva una cantidad determinada de memoria, la cual es proporcional a la longitud de la cadena.

### Mejor, peor y promedio cuando aplique
- El mejor caso seria que la cadena ingresada comience por un caracter de cierre, de esa forma no importan el resto, retorna false luego de comprobar el primer caracter.
- El caso promedio seria que la cadena ingresada termine durante la comprobacion de caracteres y termine sin revisar los todos, el programa recorre una francción significativa de la cadena.
- El peor caso seria que el programa deba recorrer toda la cadena para finalizar.


### Ubicación aproximada en la jerarquía de crecimiento del curso
- La solución se ubica en O(n), es lineal.

### Alternativa ingenua o menos eficiente
- Una solución ingenua sería verificar todas las posibles combinaciones de pares de brackets y eliminarlos iterativamente hasta que la cadena quede vacía o no se pueda reducir más. Eso incrementaria la complejidad a O(n^2) porque por cada par encontrado habría que recorrer la cadena de nuevo.


### Discución breve de robustez, degeneración y reutilización
- La solución es robusta porque maneja correctamente casos borde como: cadena vacía, solo aperturas, solo cierres y longitud máxima; todo esto sin colapsar, además el algoritmo evita desbordamientos.
- No degenerada gravemente porque incluso en el peor caso mantiene complejidad O(n). 
- Es reutilizable en la medida en que la lógica de isValid está encapsulada separadamente del Stack, permitiendo que otros módulos la usen sin conocer su implementación interna. La principal limitación de reutilización es que el Stack solo acepta char, lo que restringe su uso a problemas de caracteres.


### Instrucciones para compilar

- Usando CMake:
    1. Configurar el proyecto y crear la carpeta build
        cmake -S . -B build
    2. Compilar ejecutables
        cmake --build build

- Usando g++:
    1. Si deseas compilar la demo
        g++ -std=c++17 -O2 -I./include src/Stack.cpp demo/demo_stack.cpp -o demo_stack.exe
    2. Si deseas compilar el Benchmark
        g++ -std=c++17 -O2 -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe

### Instrucciones para ejecutar

- Usando Cmake:
    ./build/benchmark.exe  

- Usando g++:
    ./benchmark.exe

### Instrucciones para correr demo

- Usando Cmake:
    ./build/demo_stack.exe

- Usando g++:
    ./demo_stack.exe

### Breve descripción del benchmark realizado

- El benchmark consistio en una prueba para evaluar el rendimiento y comportamiento del algoritmo de validación de paréntesis.
- Se construyó un escenario del peor caso con una cadena estrictamente valida de 10000 caracteres (conformada por 5000 paréntesis de apertura seguidos de 5000 paréntesis de cierre), asi alcanzando la restricción máxima (n=10^4).

### Builds

- Build de depuración:
    g++ -std=c++17 -O0 -g -Wall -Wextra -Wpedantic -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
    ls -lh benchmark.exe
    ./benchmark.exe

- Build depurable optimizado:
    g++ -std=c++17 -Og -g -Wall -Wextra -Wpedantic -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
    ls -lh benchmark.exe
    ./benchmark.exe

- Build Release:
    g++ -std=c++17 -O2 -DNDEBUG -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
    ls -lh benchmark.exe
    ./benchmark.exe

- Build Compacto:
    1.  g++ -std=c++17 -Os -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
        ls -lh benchmark.exe
        ./benchmark.exe
    2.  g++ -std=c++17 -O1 -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
        ls -lh benchmark.exe
        ./benchmark.exe
    3.  g++ -std=c++17 -O3 -I./include src/Stack.cpp bench/benchmark.cpp -o benchmark.exe
        ls -lh benchmark.exe
        ./benchmark.exe

### Tabla resumida de builds y resultados

| Nivel de Build | Comando (g++) | Tamaño del Ejecutable | Tiempo de Ejecución (óptimo) | Tiempo de Ejecución (ingenuo) |
|---|---|---|---|---|
| Depuración | `-O0 -g` | 281 KB | 33 ms | 51873 ms |
| Depurable optimizado | `-Og -g` | 230 KB | 17 ms | 30653 ms |
| Release | `-O2 -DNDEBUG` | 145 KB | 12 msgit push | 30824 ms |
| Compacto | `-Os` | 143 KB | 10 ms | 30853 ms |
| Compacto | `-O1` | 141 KB | 11 ms | 30662 ms |
| Compacto | `-O3` | 142 KB | 12 ms | 30675 ms |

### Observaciones de sanitizers

- Al intentar compilar el código con las opciones -fsanitize=address,undefined en Windows se arrojó los errores cannot find -lasan y cannot find -lubsan.

### Resumen de cobertura
- No se usaron herramientas de cobertura formal, sin embargo se identificaron las ramas principales a cubrir: carácter de apertura, cierre con pila vacía, cierre que no coincide, cierre que sí coincide, cadena completamente válida y cadena con aperturas sin cerrar. Se probaron la mayor cantidad de casos posibles.

### Resumen de profiling
- No se usó gprof formalmente, pero por análisis estructural se puede determinar que isValid concentra la mayor parte del tiempo de ejecución ya que contiene el único bucle del programa. Las operaciones de pila dentro de ella son O(1) pero se llaman n veces. 

### Discución sobre microoptimización vs algoritmo
- Una microoptimización posible es verificar antes del bucle si la longitud de la cadena es impar. Toda cadena válida debe tener longitud par, ya que cada apertura necesita exactamente un cierre. Si s.length() % 2 != 0 retornamos false inmediatamente. Esto no cambia la complejidad, sigue siendo O(n), pero elimina la mitad de los casos antes de entrar al bucle. 

### Qué se usó de Copilot y cómo se validó

- El uso de Copilot fue de gran ayuda en el caso de proposición de soluciones, orientación en la forma correcta de completar los builds de los benchmarks