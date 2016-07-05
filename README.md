#Comparación de Ordenamiento

## Implementacion de algoritmos

Los algoritmos comparados fueron:

- counting sort
- quick sort
- insertion sort
- bitonic sort
- cocktail shaker sort
- qsort (No confundir con quick sort, este es el algoritmo de ordenamiento de
   la libreria standard de C)

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

Al correr benchmark se ejecuta `make` para compilar los archivos. Luego se ejecuta
`newlist` que genera un archivo `num.txt` con 10 millones de numeros aleatorios.
Posteriormente se ejecuta aleatoriamente cada programa correspondiente a cada
algoritmo registrando los tiempos. Esto se repite 10 veces y finalmente se calcula
el promedio para cada algoritmo.

Para guardar los resultados en un archivo `results.csv` puede ejecutar:

```
node benchmark.js -s >> results.csv
```
