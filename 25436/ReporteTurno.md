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

[Inserta aquí tu respuesta]

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

[Inserta aquí tu respuesta]

**¿Qué métodos de tu clase son `const` y por qué?**

[Inserta aquí tu respuesta]

**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

[Inserta aquí tu respuesta]

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

[Inserta aquí tu respuesta]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Inserta aquí tu respuesta]

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
