# COMPUTACION II


## TP Extra

Fecha : 03/12/2019


### Problema

El código adjuntado es una simplificación del algoritmo llamado "Proof of Work" y se usa para calcular los hashes de los bloques de una blockchain.
Se solicita:
- Primero debe detallar por escrito su funciomamiento. 
- Luego debe paralelizar la solución para poder encontar una cantidad n (pasada por argumento)  de hashes que comiencen con cinco 0 seguidos (especificada por difficulty). Cada hash nuevo se calcula en base uno anterior.
- Finalmente debe justificar el método que utilizó para paralelizar.

### Requerimientos

* La aplicación debe contener como mínimo 3 módulos.
* Debe procesar las opciones con getopt (agregar una opcion de ayuda) o con argparse.
* Debe usar los módulos Multiprocessing.Pool, ThreadPoolExecutor o ProcessPoolExecutor para calcular los hashes. 
* Debe manejar los errores.


#### Ejemplo modo de uso

~~~~~~~~~~~~~~~~~~~
./tpE.py -n 10 
./tpE.py -h  
~~~~~~~~~~~~~~~~~~~


### Objetivos

* Manejo de archivos (apertura, escritura y cierre).
* Manejo de procesos o hilos.
* Manejo de programación paralela y/o asíncrona.


