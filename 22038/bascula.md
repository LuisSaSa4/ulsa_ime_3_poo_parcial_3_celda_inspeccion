# Documentación de la clase: Bascula

**Documentación elaborada por:** Jesus Rene Pamanes Ferreira  
**Matrícula:** 22038  
**Integrante:** 2

## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

`Bascula`, representa un dispositivo de inspeccion, se encarga de consultar el peso de cada pieza que se fabrica y determinar si es necesario deshacerse de ella, esto ultimo ocurrira si la pieza no esta entre 10 y 15 kg.

**¿Quién usa tu clase y para qué?**

`CeldaInspeccion` utiliza la báscula como un dispositivo para inspeccionar cada pieza.

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?**

`Dispositivo` y `Calibrable`, porque inspecciona piezas y proporciona una descripción, además que tiene un proceso de calibración.

**Atributos propios de tu clase y para qué sirve cada uno:**

- `desfase_`: se inicializa en `0.4`, este representa el desfase de fábrica en kilogramos y se suma al peso real para obtener el peso medido. 

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

- `inspeccionar(const Pieza& pieza) const`.
- `descripcion() const`.
- `calibrar()`.

"const double pesoMedido = pieza.peso() + desfase_;

return pesoMedido >= 10.0 && pesoMedido <= 15.0;"


**¿Qué métodos de tu clase son `const` y por qué?**

`inspeccionar()`, `descripcion()` y `getDesfase()`.

solo consultan el estado de la pieza, por lo que es buena practica declarar que
no se deben de modificar durante la ejecucuion del metodo.


**Lo particular de tu clase:**

El desfase de fábrica se representa con desfase_ = 0.4 kg y se aplica sumándolo al peso real de la pieza. `calibrar()` elimina ese desfase con un valor de `0.0` e informa que la calibración fue exitosa devolviendo `true`.

## 3. Pruebas

P-02 pesa 15.0 kg, una vez calibrada la báscula, en la ejecucuion debe de aceptarse porque el límite superior está incluido. 

P-08 pesa 9.5 kg y debe rechazarse por que esta debajo del mínimo. 

P-09 pesa 14.8 kg, sin calibrar se mediría como 15.2 kg y se rechaza, mientras que calibrada se deberia de aceptar.

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

"La regla debe aplicarse al peso medido, no directamente al peso real"

Se debe sumar primero `desfase_` al peso de la pieza y comparar ese resultado con los límites.

**Errores que encontraste y cómo los corregiste:**
En bascula solo encontre que std::string nombre sobrababa, no era necesario, no encontre nada más.

Tambien en la clase `calibrable.h` el metodo `calibrar`, antes era de tipo const, se modifico porque el desfase va oscilando entre 0.4 y 0.0.