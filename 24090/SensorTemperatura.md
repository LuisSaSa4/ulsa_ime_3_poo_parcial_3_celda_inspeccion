# Documentación de la clase: SensorTemperatura

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** Luis Samano Saavedra

**Matrícula:** 24090

**Integrante:** 1

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

La clase SensorTemperatura representa un sensor encargado de revisar la temperatura de las piezas que pasan por la celda de inspección. Su función es determinar si la temperatura de una pieza se encuentra dentro de un rango permitido, que es de 20.0 °C a 35.0 °C. Si la pieza cumple con este rango se considera aceptada por el sensor, de lo contrario se rechaza.

**¿Quién usa tu clase y para qué?**

La clase CeldaInspeccion utiliza los dispositivos de inspección para evaluar las piezas que pasan por la celda. SensorTemperatura puede ser utilizado a través de un puntero de tipo Dispositivo, permitiendo que la celda realice la inspección sin depender directamente de la clase concreta del sensor.

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** 

SensorTemperatura hereda de la clase Dispositivo, porque es un dispositivo de inspección y necesita cumplir con las funciones que se le fueron establecidas por la clase base, esto le permite que pueda ser utilizada junto con los demás dispositivos de la celda de forma polimórfica.

**Atributos propios de tu clase y para qué sirve cada uno:**

La clase SensorTemperatura no tiene atributos propios, ya que no necesita almacenar información adicional para realizar su inspección o su tarea, la temperatura de cada pieza se obtiene directamente del objeto Pieza que recibe como parámetro.

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

1.- inspeccionar(const Pieza& pieza) const: obtiene la temperatura de la pieza y verifica que sea mayor o igual a 20.0 °C y menor o igual a 35.0 °C. Devuelve true si cumple el rango y false si está fuera de él.

2.- descripcion() const: devuelve el nombre del dispositivo, que es "Sensor de temperatura".

**¿Qué métodos de tu clase son `const` y por qué?**

Los métodos inspeccionar() y descripcion() son const, porque no modifican el estado del sensor. El método inspeccionar() únicamente consulta la temperatura de una pieza para determinar si cumple con el rango permitido, mientras que descripcion() solamente devuelve el nombre del dispositivo.

**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

La clase utiliza final, lo que significa que no permite que otras clases hereden de ella porque el sensor de temperatura ya cuenta con una función específica y definida para inspeccionar las piezas, por lo que no se necesita crear clases derivadas de él en este proyecto.

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**


Primero realicé una prueba individual con tres piezas, utilizando diferentes temperaturas para comprobar que el sensor acepta únicamente aquellas que se encuentran dentro del rango establecido:

Pieza P-01: temperatura de 18 °C, fue rechazada porque está por debajo del límite mínimo.

Pieza P-02: temperatura de 25 °C, fue aceptada porque se encuentra dentro del rango permitido.

Pieza P-03: temperatura de 38 °C, sue rechazada porque supera el límite máximo.

Los resultados que obtuve coincidieron con lo que se esperaba, lo cual me permitio comprobar que la regla de inspección que implemente funcionaba correctamente.

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Mientras realizaba mi maquina tuve varias dudas, como por ejemplo no sabia como usar el const, override y final ya que al principio no tenia bien claro para que sirvia cada uno y mucho menos sabia como utilizarlo, para saber como funcionaban investigue que eran, como se usan y observe como estos se usaban en la clase Dispositivo. Tambien tuve que comprender como la herencia le permite al sensor temperatura utilizar lo que esta dentro de la celda de inspeccion mediante los punteros.

**Errores que encontraste y cómo los corregiste:**

Al principio tuve algunos problemas al compilar el proyecto ya que faltaban algunos métodos en las clases principales y tambein tuve un problema con el uso de dynamic_cast, para poder solucionarlo revisé los errores que mostraba el compilador y fui haciendo los cambios necesarios poco a poco. Después volví a compilar el programa para comprobar que todo funcionara correctamente y que mi clase SensorTemperatura se integrara bien con las demas que crearon mis compeñeros.

Otro problema que tuve que solucionar y con lo que mas batalle fue que los métodos de mi clase estuvieran declarados correctamente y coincidieran con los de Dispositivo, especialmente inspeccionar y descripcion. Para corregirlo revisé los archivos  .h y .cpp y comprobé que las declaraciones y las implementaciones fueran iguales. Después compilé otra vez para revisar que ya no hubieran problemas.
