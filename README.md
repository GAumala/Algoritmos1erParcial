#Comparación de Ordenamiento

## Implementacion de algoritmos

Los algoritmos comparados fueron:

- counting sort
- quick sort
- insertion sort
- bitonic sort
- cocktail shaker sort
- qsort (No confundir con quick sort, este es el algoritmo de ordenamiento de la libreria standard de C)

 Cada uno de estos algoritmos esta implementado en C. Hay un archivo .c para cada
 uno con su respectivo nombre. Para generar los ejecutables basta con ejecutar
 `make` en este directorio.

Los ejecutables generados son:

- countsort
- insertionsort
- quicksort
- qsort_gcc
- shakersort
- bitonicsort

Cada uno de estos programas en C lee el archivo `num.txt` y lo ordena con su
correspondiente algoritmo. Si se le pasa el parametro `--summary` se imprime
un pequeño resumen del ordenamiento.  Con el parametro `--verbose` se imprime
toda la lista ordenada.

## Registro de tiempos y promedios

Las pruebas estan implementadas en javascript en el archivo `benchmark.js`. se
lo puede ejecutar con node.js usando:

```
node benchmark.js
```

Al correr benchmark ocurre lo siguiente:

1. se ejecuta `make` para compilar los archivos. Se generan los ejecutables para cada algoritmo, y el de
`newlist` que genera un archivo `num.txt` con 10 millones de numeros aleatorios.
2. Al recibir la señal de que `make` termino, se ejecuta `newlist`
3. Al recibir la señal de que `newlist` termino, se ejecuta aleatoriamente cada programa correspondiente a cada algoritmo registrando los tiempos. El tiempo se lo mide desde que se llama a a ejecutar
el proceso has que este termina con código 0.

Los pasos 2 y 3 se repiten 10 veces y finalmente se calcula el promedio para cada algoritmo.

Para guardar los resultados en un archivo `results.csv` puede ejecutar:

```
node benchmark.js -s >> results.csv
```
