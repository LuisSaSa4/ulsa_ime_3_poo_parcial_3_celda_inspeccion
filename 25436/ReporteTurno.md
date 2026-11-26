# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** Fernando caleb Román Zamarripa
**Matrícula:** 25436
**Integrante:** 5

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

La clase ReporteTurno (definida dentro del namespace calidad) representa el resumen estadístico y de trazabilidad de la producción evaluada durante un turno de inspección de calidad.

A diferencia de los dispositivos de medición (Bascula, CalibradorLaser, SensorTemperatura, CamaraVision), esta clase no revisa propiedades físicas ni tolerancias de cada pieza, sino que registra los resultados finales de la inspección: contabiliza el total de piezas evaluadas (piezasInspeccionadas_), cuántas aprobaron (piezasAceptadas_), cuántas fallaron (piezasRechazadas_) y lleva un conteo acumulado de cuántos rechazos fueron provocados por cada dispositivo identificado por su ID ("B-01", "L-01", "T-01", "V-01").

**¿Quién usa tu clase y para qué?**

CeldaInspeccion: Mantiene una instancia interna de ReporteTurno (consultable mediante celda.reporte()) y la actualiza conforme ejecuta celda.procesar(pieza) sobre cada pieza del turno

La función main() (flujo principal y validación): Al finalizar el recorrido de piezasDelTurno(), imprime el resumen legible en consola mediante std::cout << celda.reporte() y construye un objeto ReporteTurno esperado(...) para verificar mediante celda.reporte() == esperado que el comportamiento de toda la celda coincida con el resultado esperado del turno.


## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

 Esta clase  no hereda  nada incluso de dispositivo por que no tiene un,es un  o usa un  , por qu eno usa dspositivo pues  este representa  un instrumento maquina fisica  que es encargado de trajar la pieza pero reporte turno  es un  organizador de metricas o informacion  , no mide no  gestiona  , no necesita calibrarse  , hacerlo dispositivo romperia las relaciones al ser una clase que solo se dedica a guaradar informacion no medir    ni evaluar un pieza.

**Atributos propios de tu clase y para qué sirve cada uno:**

Todos los atributos son privados (private) para encapsular los contadores y garantizar que solo se modifiquen de forma controlada a través de sus métodos públicos:

int piezasInspeccionadas_: Almacena el número total de piezas evaluadas en el turno. Se incrementa en 1 cada vez que se invoca registrarPieza(...) y, en el constructor parametrizado, se inicializa automáticamente como aceptadas + rechazadas para evitar inconsistencias.

int piezasAceptadas_: Contabiliza las piezas que pasaron satisfactoriamente todos los dispositivos de la celda.

int piezasRechazadas_: Contabiliza las piezas que fueron rechazadas por al menos un dispositivo durante su inspección.



**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

No sobreescribe  ningun metodo  con override   al no heredar ninguna clase  base ni interfaz polimofica , no implementa reglas de inspeccion , unicamente recibe el resultado booleano.

**¿Qué métodos de tu clase son `const` y por qué?**
int inspeccionadas() const: Retorna el total de piezas inspeccionadas sin modificar el contador.

int aceptadas() const: Retorna el total de piezas aceptadas sin modificar el estado.

int rechazadas() const: Retorna el total de piezas rechazadas sin modificar el estado.

const std::map<std::string, int>& rechazosPorDispositivo() const: Retorna una referencia constante al mapa interno de rechazos por dispositivo, evitando copias innecesarias y protegiendo el mapa contra modificaciones externas.


**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

ReporteTurno() (constructor por defecto): Inicializa en 0 los tres contadores (piezasInspeccionadas_, piezasAceptadas_, piezasRechazadas_) y deja vacío el mapa rechazosPorDispositivo_ para comenzar un turno limpio dentro de CeldaInspeccion.

operator==: Sobrecargado como método miembro constante para comparar dos reportes. Decide que dos instancias de ReporteTurno son iguales si y solo si coinciden exactamente sus cuatro atributos
## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**
Se comprobo ejecutando  el turno dee DatosTurno.cpp
a traves de CeldaInspeccion en main  con  los 4 dispositivos conectados

en el reporte las piezas  1 2 4 10 11  y 12 cumplieron con todo las inspecciones  piezas rechazadas  por fallas 

3 rechazada por peso, bascula
5 rechzada por calibrador laser
6 rechazada por camara de vision 2 defectos
7 y 9  rechazada por  sensor de temperatura
8 rechazada por bascula  calibrador laser y camara de vision

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Relación entre piezas rechazadas y rechazos por dispositivo: En el lote (P-01 a P-12) hay 6 piezas rechazadas pero 8 rechazos en total porque P-08 falla en 3 dispositivos a la vez. Por eso registrarPieza y registrarRechazo van separados: una pieza defectuosa suma 1 rechazo general, pero puede acumular varios registros por dispositivo.

Consistencia en el constructor parametrizado: Para evitar totales erróneos al crear el reporte esperado, el constructor solo recibe aceptadas y rechazadas y calcula piezasInspeccionadas_(aceptadas + rechazadas) automáticamente

**Errores que encontraste y cómo los corregiste:**

alta de const al usar celda.reporte(): Como celda.reporte() devuelve una referencia constante, el compilador exigía que operator== y los getters tuvieran const al final. Se agregó el calificador en .h y .cpp.
