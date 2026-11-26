<!-- Resultados y respuestas de los experimentos 1 y 2. -->

# Experimentos de memoria, herencia y destructores

## Experimento 1: Memoria y object slicing bajo herencia

### Objetivo

Observar cómo cambia el tamaño de los objetos al utilizar herencia y métodos virtuales, además de comprobar qué sucede cuando se pasa un objeto derivado por valor a una función que recibe un objeto de la clase base.

### Resultados obtenidos

**1. Clases sin método virtual**

- Tamaño de BaseSimple: 4 bytes.
- Tamaño de DerivadaSimple: 8 bytes.

**2. Clases con método virtual**

- Tamaño de Base: 16 bytes.
- Tamaño de Derivada: 16 bytes.

**3. Prueba de object slicing**

Al pasar un objeto Derivada por valor a una función que recibe Base, el resultado fue:

```text
Metodo de Base
```

Esto demuestra que al pasar el objeto por valor se pierde la parte correspondiente a la clase derivada.

### Preguntas

**1. ¿Por qué sizeof(Derivada) es mayor o igual que sizeof(Base)?**

Porque la clase derivada contiene los atributos heredados de la clase base y puede agregar sus propios atributos. Por eso su tamaño puede ser mayor o igual.

**2. ¿Qué cambió al agregar una función virtual?**

El tamaño de las clases aumentó debido al mecanismo interno que utiliza C++ para manejar el polimorfismo. En nuestra prueba, BaseSimple ocupaba 4 bytes y Base pasó a ocupar 16 bytes. El tamaño exacto depende del compilador y la plataforma.

**3. ¿Qué se pierde al pasar Derivada por valor a una función que recibe Base?**

Se pierde la parte propia de la clase derivada. Este comportamiento se conoce como object slicing.

**4. ¿Por qué esto no debería ocurrir con Dispositivo y cómo se evita?**

En nuestro proyecto utilizamos punteros de tipo Dispositivo* para trabajar con diferentes dispositivos. Esto permite conservar el objeto completo y utilizar el polimorfismo. También se puede evitar pasando objetos por referencia, en lugar de hacerlo por valor.

## Experimento 2: Destructor virtual vs. no virtual

### Objetivo

Comprobar la diferencia entre utilizar un destructor virtual y uno no virtual cuando se destruye un objeto derivado mediante un puntero de la clase base.

### Resultados obtenidos

*1. Destructor no virtual*

El compilador mostró la siguiente advertencia:

text
warning: deleting object of polymorphic class type 'BaseSimple'
which has non-virtual destructor might cause undefined behavior


La salida obtenida fue:

text
=== Destructor NO virtual ===
Destructor de BaseSimple


En esta ejecución solamente apareció el destructor de BaseSimple.

*2. Destructor virtual*

La salida obtenida fue:

text
=== Destructor VIRTUAL ===
Destructor de DerivadaVirtual
Destructor de BaseVirtual


En este caso se ejecutaron primero el destructor de la clase derivada y después el de la clase base.

### Preguntas

*1. ¿Cuál fue la diferencia entre ambos resultados?*

Cuando el destructor de la clase base no era virtual, solamente apareció el mensaje de BaseSimple en nuestra ejecución. Cuando utilizamos un destructor virtual, se ejecutaron los destructores de ambas clases en el orden correcto.

*2. ¿Qué problema podría existir con los recursos de un objeto?*

Si una clase derivada utiliza memoria dinámica u otros recursos, estos podrían no liberarse correctamente al destruir el objeto mediante un puntero base sin destructor virtual. Esto puede provocar problemas y comportamiento indefinido.

*3. ¿En qué situación podría ocurrir este problema en nuestro proyecto?*

Podría ocurrir si en el futuro la clase CeldaInspeccion tuviera que eliminar dinámicamente los dispositivos mediante punteros Dispositivo*. Por eso es importante que la clase base tenga un destructor virtual. Actualmente los dispositivos se crean en main y no se eliminan mediante esos punteros.
