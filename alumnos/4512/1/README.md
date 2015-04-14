Ejercicio

Remover los elementos duplicados de un arreglo.


Compilation
```
gcc -g -Wall -o e1 e1.c
```

Pasos para resolver el problema:

    1)Ordenar el vector virgen (para facilitar el paso 2)
    2)Busco la cantidad de valores unicos en el vector ordenado
    3)Asigno espacio para el nuevo vector de valores sin repetir sabiendo la cantidad de valores unicos
    4)Escribo el vector sin repetir con valores unicos del vector virgen ordenado
    5)Libero la memoria asignada al vector de valores sin repetir

    Consulta:

    -¿Conviene asignar todo el bloque de memoria de una o conviene hacerlo por cada elemento?
    ¿es una decision sobre si exigir la memoria sobre el procesador o el procesador sobre
        la memoria?



