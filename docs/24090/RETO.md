# Reto opcional: Modo aleatorio

**Reto elegido:** Modo aleatorio.

## ¿Qué se agregó?

Se agregó una segunda modalidad de inspección en `main.cpp`. Ahora el programa permite elegir entre el turno original de 12 piezas y un turno generado aleatoriamente.

Para generar las piezas se utilizó la biblioteca `<random>`, el motor `std::mt19937` y una semilla fija con valor 12345.

Se generaron valores aleatorios para el peso, largo, temperatura, defectos y dureza de cada pieza.

## ¿Qué se modificó?

Se modificó `main.cpp` para permitir elegir el modo de inspección y generar 12 piezas aleatorias cuando se selecciona la segunda opción.

El turno original se conservó y sigue utilizando las piezas definidas en `piezasDelTurno()`.



## Resultado

Se probaron los dos modos de inspección. El turno original conservó su comparación con el reporte esperado y el turno aleatorio generó e inspeccionó 12 piezas nuevas correctamente.