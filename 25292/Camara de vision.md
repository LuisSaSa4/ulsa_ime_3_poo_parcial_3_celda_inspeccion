# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<matrícula>/<Clase>.md` (por ejemplo, `docs/0123456/Bascula.md`) y llena tu copia. No modifiques la plantilla.

**Documentación elaborada por:** [Inserta aquí tu nombre]
**Matrícula:** 25292
**Integrante:** yurik david alarcon gtz.
## 1. Propósito

**¿Qué representa tu clase y qué revisa o registra de cada pieza?**

Representa un sistema de inspección óptica industrial dentro de la línea de producción. Su función principal es analizar visualmente las características físicas y superficiales de cada pieza (como integridad estructural, ausencia de grietas, defectos de acabado, o presencia y correcta posición de componentes) a partir de los parámetros visuales registrados en la pieza, determinando si cumple con los estándares de calidad establecidos o si debe ser rechazada

**¿Quién usa tu clase y para qué?**

Representa un sistema de inspección óptica industrial dentro de la línea de producción. Su función principal es analizar visualmente las características físicas y superficiales de cada pieza (como integridad estructural, ausencia de grietas, defectos de acabado, o presencia y correcta posición de componentes) a partir de los parámetros visuales registrados en la pieza, determinando si cumple con los estándares de calidad establecidos o si debe ser rechazada

## 2. Decisiones de diseño

**¿De qué clase o clases hereda tu clase y por qué?** (Si es `ReporteTurno`, explica por qué no hereda de `Dispositivo`.)

Hereda públicamente de la clase base abstracta Dispositivo (o DispositivoInspeccion). Esto permite que CamaraVision forme parte de la jerarquía polimórfica del sistema y sea tratada de manera uniforme junto con otros equipos (como básculas o sensores) mediante punteros o referencias a la clase base, sin que la celda de inspección necesite conocer los detalles internos de su funcionamiento óptico.

**Atributos propios de tu clase y para qué sirve cada uno:**

resolucionMP (o resolucion / umbralConfianza): Almacena la capacidad óptica o el porcentaje mínimo de nitidez/confianza requerido para que una captura sea válida y confiable durante el análisis.

iluminacionActiva (o intensidadLuz): Indica si el sistema de iluminación auxiliar está encendido o calibrado para evitar falsos negativos por sombras o reflejos.

piezasAnalizadas / defectosDetectados: Contadores internos que llevan el registro estadístico de las inspecciones visuales realizadas y las fallas encontradas durante la operación.

**Métodos que sobrescribes con `override` y cómo implementaste la regla de inspección:**

inspeccionar(const Pieza& pieza) (o el método virtual puro equivalente de Dispositivo): Evalúa si la pieza pasa el control de calidad visual. La regla de inspección verifica primero que la cámara tenga condiciones adecuadas de operación (por ejemplo, iluminación activa o resolución mínima) y luego comprueba los atributos visuales de la pieza (que no presente defectos superficiales/grietas y que su nivel de acabado o integridad supere el umbral permitido). Si cumple ambas condiciones, aprueba la pieza; de lo contrario, registra el fallo y retorna false (o el estado de rechazo).

obtenerInfo() / mostrarEstado(): Sobrescribe el método de descripción para devolver los datos específicos de la cámara (identificador, resolución y estado de iluminación).

**¿Qué métodos de tu clase son `const` y por qué?**

Son const todos los métodos de consulta (getters como getResolucion(), isIluminacionActiva(), getPiezasAnalizadas()) y los métodos de visualización o reporte de estado (mostrarEstado() / obtenerResumen()), ya que únicamente leen los atributos del objeto para informar al exterior sin modificar el estado interno de la cámara. (Si inspeccionar tampoco altera atributos de la instancia o usa miembros mutable, también se marca como const para garantizar seguridad de lectura).

**Lo particular de tu clase.** Responde solo lo que corresponda a tu clase:
- `Bascula` o `CalibradorLaser`: ¿cómo modelaste el desfase y qué hace `calibrar()`?
- `SensorTemperatura`: ¿qué significa `final` y por qué tiene sentido en esta clase?
- `ReporteTurno`: ¿qué sobrecargas implementaste (constructores y operadores) y cómo decide `operator==` que dos reportes son iguales?
- `CamaraVision` o `Durometro`: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

CamaraVision o Durometro: ¿qué tuviste que hacer para que la celda pudiera usar tu clase sin modificarla?

Para que la celda de inspección pudiera integrar CamaraVision sin alterar su código fuente (cumpliendo con el principio Abierto/Cerrado), se aplicó el patrón de diseño Adapter (o polimorfismo estricto mediante la interfaz Dispositivo). Se encapsuló la lógica específica del análisis de visión artificial (que originalmente podía tener métodos o firmas propias como capturarImagen() o analizarSuperficie()) dentro de la interfaz estándar heredada de Dispositivo (inspeccionar()). De este modo, la celda simplemente recibe un Dispositivo* y ejecuta el método genérico sin acoplarse a la implementación particular de la cámara.

## 3. Pruebas

**¿Cómo comprobaste que tu clase funciona? ¿Qué piezas del turno te sirvieron para verificarla?**

Se realizaron pruebas unitarias e integración dentro de la simulación del turno instanciando objetos de CamaraVision tanto de forma directa como mediante punteros polimórficos de tipo Dispositivo*. Se utilizaron piezas de prueba del lote del turno con distintos escenarios:

Pieza en buen estado (nominal): Sin defectos superficiales y con parámetros dentro de tolerancia, verificando que la cámara la aprobara correctamente.

Pieza con defecto superficial / grieta: Para comprobar que la regla de inspección detectara la anomalía y la rechazara.

Prueba de condiciones de cámara (ej. iluminación apagada o baja confianza): Para verificar que el dispositivo manejara adecuadamente los casos límite antes de emitir un diagnóstico.

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Integración con la celda sin modificarla: Al inicio surgió la duda de cómo conectar métodos específicos del análisis de imagen con el flujo general de la celda. Se resolvió revisando los métodos virtuales de la clase base Dispositivo y adaptando la lógica de visión dentro de la sobrescritura con override.

Uso de const y paso de parámetros: Hubo dudas sobre cómo recibir el objeto Pieza sin generar copias innecesarias ni permitir modificaciones accidentales; se resolvió pasándolo por referencia constante (const Pieza&).

**Errores que encontraste y cómo los corregiste:**

Firma incompatible en el método sobrescrito: El compilador marcó un error con la palabra clave override porque faltaba el calificador const al final de la firma del método en CamaraVision.h respecto a Dispositivo.h. Se corrigió igualando exactamente la firma en ambos archivos (.h y .cpp).

Inclusión de encabezados (dependencias): Se presentaron errores de referencia indefinida al enlazar la clase con Pieza y Dispositivo; se solucionó agregando las directivas #include correspondientes y guardas de inclusión (#pragma once / #ifndef).
