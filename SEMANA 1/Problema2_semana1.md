#### Ejercicio 2. Cadena bien balanceada usando el ADT Pila

Una cadena formada por los símbolos `(`, `)`, `[`, `]`, `{`, `}` se dice **bien balanceada** si cada símbolo de apertura tiene su correspondiente símbolo de cierre y el orden de anidamiento es correcto.

##### Se pide

1. Especificar las operaciones básicas del **ADT Pila** que se necesitan para resolver este problema.

    * Se debe hacer uso de la operaciones básicas del **ADT Pila**: pop, push y top.

2. Diseñar un algoritmo que determine si una cadena está bien balanceada.

    función estaBalanceada(cadena):
    pila = nueva Pila()
    
    para cada c en cadena:
        si c es '(' o '{' o '[':
            pila.push(c)
        sino:
            si pila.estaVacia():
                retornar falso
            
            caracterTope = pila.top()
            pila.pop()
            
            si c == ')' y caracterTope != '(':
                retornar falso
            si c == '}' y caracterTope != '{':
                retornar falso
            si c == ']' y caracterTope != '[':
                retornar falso
                
    retornar pila.estaVacia()

3. Enunciar una invariante del recorrido de la cadena.

    * Antes de iniciar el bucle (i=0), el prefijo de la cadena procesada es vacío, por lo que no hay paréntesis sin cerrar.

4. Justificar la correctitud básica del algoritmo.

    * Al inicio de la iteración i, la pila contiene todos los paréntesis de apertura del prefijo s[0...i-1] que aún no han sido cerrados, conservando el orden en que fueron abiertos (el útimo en abrir se encuentra en el tope de la pila).

5. Indicar su complejidad temporal en función de la longitud de la cadena.

    * La complejidad temporal es O(n) donde n es la longitud de la cadena. El algoritmo recorre cada caracter exactamente una vez por bucle for. Dentro cada iteración se ejecutan las operaciones de pila las cuales son O(1). Por tanto T(n) es lineal.