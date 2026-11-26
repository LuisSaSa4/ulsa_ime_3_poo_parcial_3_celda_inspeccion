# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** Daniel Gerardo Guerra Rodriguez
**Matrícula:** 25238
**Integrante:** 4

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

un aparato que permite hacer mediciones precisas sin siquiera tocar la pieza y revisa el largo de la pieza se encuentre entre 49.5 y 50.5

**¿Quién usa tu clase y para qué?**

la clase celda de inspeccion porq que esta utiliza todos los dispositivos para asi verificar que la pieza contenga las especificaciones definidas

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

dispositivo: por que es un tipo derivado de dispositivo de inspeccion que necesita usar muchas de sus funciones ya especificadas

Calibrable: el dispositivo preenta un desfase que necesita ser corregido

**Atributos propios de tu clase y para qué sirve cada uno:**

double getDesfase() const; devuelve el valor del desfase

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

bool inspeccionar(const Pieza& pieza) const override;revisa que el largo de la pieza se encuenttre dentro de un limite aceptable

const std::string& descripcion() const override; devuelve el nombre de la maquina

bool calibrar() override; elimina el desfase presente en la maquina


**¿Qué métodos de tu clase son `const` y por qué?**

bool inspeccionar(const Pieza& pieza) const override;  el verdadero o falso que devuelve no se debe modificar

const std::string& descripcion() const override; no se puede cambiar el nombre de la maquina


**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

el desfase es una variable privada que no se puede modificar al menos que lo haga la funcion, calibrar() arregla el desfase y devuelve true cuando lo haga

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

[Inserta aquí tu respuesta]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Inserta aquí tu respuesta]

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
