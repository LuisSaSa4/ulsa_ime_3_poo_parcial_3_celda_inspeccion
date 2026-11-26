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

[Inserta aquí tu respuesta]

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

[Inserta aquí tu respuesta]

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
