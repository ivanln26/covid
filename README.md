# Covid Argentina

Visualizador de datos de los casos de COVID-19 de Argentina en la terminal.

El dataset referido a los casos registrados es obtenido mediante el ministerio de salud: [aquí](http://datos.salud.gob.ar/dataset/covid-19-casos-registrados-en-la-republica-argentina).

## Manual de uso

```shell
$ ./covid19 [ARG..] file.csv


Argumentos:
    -estad
        Mostrará la información estadística
    -p_casos int
        Mostrará las n primeras provincias con más contagios ordenadas de mayor a menor.
        Si n no es pasado, se mostrarán todas las provincias.
    -p_muertes int
        Mostrará las n provincias con más muertes ordenadas de más a menos.
        Si n no es pasado, se mostrarán todas las provincias.
    -casos_edad int
        Mostrará los datos de los casos donde la edad sea "años" (ordenados por nombre de provincia).
    -casos_cui [fecha]
        Mostrará los datos de los casos que estuvieron en cuidados intensivos ordenados por fecha de cuidados intensivos.
        Si fecha está indicada, se mostrarán solo las fechas mayores a esta.
```

### Información estadística:

* Cantidad total de muestras
* Cantidad total de infectados
* Cantidad de fallecidos
* % de infectados por muestras
* % de fallecidos por infectados
* Cantidad de infectados por rango etario (rango de 10 años)
* Cantidad de muertes por rango etario (rango de 10 años)
