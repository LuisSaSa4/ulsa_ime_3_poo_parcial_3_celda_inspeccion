# Celda Robótica de Inspección de Calidad

Proyecto del Parcial 3 de Programación Orientada a Objetos.

La guía completa del proyecto está en [PROYECTO.md](PROYECTO.md). Léanla antes de empezar.

## 1. Equipo

| Integrante | Matrícula | Nombre | Usuario de GitHub | Clase |
| --- | --- | --- | --- | --- |
| 1 | 24090| Luis Samano Saavedra| LuisSaSa4 | SensorTemperatura|
| 2 | 22038 | Jesus Rene Pamanes Ferreira | TacocraftG | Bascula |
| 3 | | | | |
| 4 |25238 |Daniel Gerardo Guerra Rodriguez | mohawkcat |CalibradorLaser |
| 5 | | | | |
| 6 (solo equipo de seis) | | | | |

## 2. Cómo compilar y ejecutar

Escriban el comando exacto que usa el equipo para compilar y el comando para ejecutar.

[Inserta aquí tu respuesta]

## 3. Contrato de `Dispositivo` y `Calibrable`

**¿Qué errores dio el compilador al compilar el repositorio base y qué significaba cada uno?**

src/CeldaInspeccion.cpp: In member function 'void calidad::CeldaInspeccion::iniciarTurno()':
src/CeldaInspeccion.cpp:13:29: error: cannot 'dynamic_cast' 'd' (of type 'class calidad::Dispositivo*') to type 'class calidad::Calibrable*' (source type is not polymorphic)
   13 |         if (Calibrable* c = dynamic_cast<Calibrable*>(d)) 
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/CeldaInspeccion.cpp:14:65: error: 'class calidad::Dispositivo' has no member named 'descripcion'
   14 |             std::cout << "Calibrando " << d->id() << " (" << d->descripcion() << ") ... "
      |                                                                 ^~~~~~~~~~~
src/CeldaInspeccion.cpp:15:30: error: 'class calidad::Calibrable' has no member named 'calibrar'; did you mean 'Calibrable'?
   15 |                       << (c->calibrar() ? "OK" : "FALLA") << '\n';
      |                              ^~~~~~~~
      |                              Calibrable                                                                        >                                                          al_3_celda_inspeccion> 

**Error 1: source type is not polymorphic**
<br>
El programa intenta convertir un puntero de tipo Dispositivo* a Calibrable* utilizando dynamic_cast, el problema es que Dispositivo todavía no es una clase polimórfica, porque no tiene ningún método virtual.
Para que dynamic_cast funcione la clase de origen debe tener al menos un método virtual.

<br>

**Error 2. Dispositivo has no member named descripcion**
<br>
La celda intenta obtener la descripción del dispositivo para imprimir qué aparato está calibrando.
Sin embargo, la clase Dispositivo todavía no tiene declarado un método llamado descripcion().
<br>

**Error 3. Calibrable has no member named calibrar**
<br>
La celda intenta ejecutar el método calibrar() para ajustar los dispositivos que tienen esa capacidad.
Sin embargo, la clase Calibrable todavía no declara dicho método.
<br>
<br>

**¿Qué métodos agregaron a `Dispositivo`? ¿Cuáles son virtuales puros, cuáles son `const` y por qué el destructor es virtual?**

[Inserta aquí tu respuesta]

**¿Qué agregaron a `Calibrable` y por qué no tiene atributos?**

[Inserta aquí tu respuesta]

## 4. Cálculo a mano del reporte

Turno de 12 piezas, con la celda ya calibrada. Escriban `ACEPTA` o `RECHAZA` por dispositivo. La columna D-01 solo la llena el equipo de seis.

| Pieza | B-01 | L-01 | V-01 | T-01 | D-01 | Resultado |
| --- | --- | --- | --- | --- | --- | --- |
| P-01 | 12 | 50 | 25 | 0 | * | ACEPTA |
| P-02 | 15 | 50 | 24 | 0 | * | ACEPTA |
| P-03 | 16.2 | 50.1 | 25 | 0 | * | RECHAZA |
| P-04 | 12.5 | 50.5 | 26 | 0 | * | ACEPTA |
| P-05 | 11 | 50.7 | 25 | 0 | * | RECHAZA |
| P-06 | 13 | 50.2 | 23 | 2 | * | RECHAZA |
| P-07 | 12.2 | 49.9| 41 | 0 | * | RECHAZA |
| P-08 | 9.5 | 51 | 25 | 1 | * | RECHAZA |
| P-09 | 14.8 | 50 | 35 | 0 | * | ACEPTA |
| P-10 | 10.5 | 49.6 | 22 | 0 | * | ACEPTA |
| P-11 | 13.5 | 50.3 | 19.5 | 0 | * | RECHAZA |
| P-12 | 12.8 | 49.9 | 27 | 0 | * | ACEPTA |

**Reporte esperado (inspeccionadas, aceptadas, rechazadas y rechazos por dispositivo):**

| Concepto | Equipo de 5 |
| --- | --- |
| Inspeccionadas | 12 |
| Aceptadas | 6 | 
| Rechazadas | 6 | 
| Rechazos B-01 (Bascula) | 2 | 
| Rechazos L-01 (Calibrador Laser)| 2 | 
| Rechazos T-01 (Sensor de temperatura)| 2 | 
| Rechazos V-01 (Camara de vision)| 2 |
| Total de rechazos registrados| 8 |

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron y cómo lo corrigieron?**

[Inserta aquí tu respuesta]

## 5. Diagrama de clases

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen en la raíz del repositorio como `diseno_solucion.png`.

![Diagrama de clases](diseno_solucion.png)

## 6. Documentación individual

| Integrante | Documentación de su clase | Rama del reto opcional |
| --- | --- | --- |
| | `docs/<matrícula>/<Clase>.md` | `<matrícula>` o "No" |
| | | |
| | | |
| | | |
| | | |
| | | |

Los resultados de los experimentos están en [docs/experimentos.md](docs/experimentos.md).

## 7. Prueba de extensibilidad

Practiquen agregar un dispositivo nuevo antes de entregar.

**¿Qué archivos tuvieron que crear o modificar? ¿Tuvieron que tocar `CeldaInspeccion`?**

[Inserta aquí tu respuesta]

## 8. Reflexión del equipo

**¿Qué aprendieron en este proyecto?**

[Inserta aquí tu respuesta]

**¿Qué cambiarían de su proceso de trabajo como equipo?**

[Inserta aquí tu respuesta]
