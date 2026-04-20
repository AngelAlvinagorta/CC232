## Actividad 2-CC232

### Integrante

   * Alvinagorta Huapaya Angel Andres

#### Bloque 1

1. Explique con sus palabras qué significa que un arreglo use memoria contigua.

   * Significa que todos sus elementos se almacenan uno después de otro en un bloque continuo de memoria.

2. Explique por qué acceder a `A[i]` es una operación de costo `O(1)`.

   * Porque se calcula directamente la dirección del elemento sin tener que recorrer otros

3. Explique la diferencia entre `size` y `capacity`.

   * `size` es la cantidad actual de elementos que el arreglo contiene.
   * `capacity` es el número de elementos que el arreglo puede almacenar.

4. Explique por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.

   * Esto es debido a que un arreglo dinámico usa un bloque contiguo de memoria y al requerir más espacio se necesitará un bloque más grande que incluya sus elementos antiguos juntos.

5. Explique por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.

   * Copiar n elementos cuesta `O(n)` y despues de cada copia hay espacio para `n` inserciones sin nuevos costos, por lo que el costo de la copia se reparte entre las inserciones adicionales y cada inserción tendrian un costo constante. 

6. Compare `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?

   * 

7. Explique qué mejora `FastArrayStack` respecto a `ArrayStack`.

   * 

8. Explique cuál es la idea espacial central de `RootishArrayStack`.

   * 

9. Explique por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.

   * 

10. Explique qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.

   * 

#### Bloque 2
(tabla y respuestas)

#### Bloque 3
(respuestas)

#### Bloque 4
(respuestas)

#### Bloque 5
(respuestas)

#### Bloque 6
(respuestas)

#### Bloque 7
(respuesta final)

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación:
```

