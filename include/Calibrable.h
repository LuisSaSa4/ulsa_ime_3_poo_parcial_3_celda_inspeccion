
#pragma once

namespace calidad {

class Calibrable {
public:
    virtual bool calibrar() = 0;

    virtual ~Calibrable() = default;

    // TODO (equipo): definan la interfaz de los dispositivos que se pueden calibrar.
    //  - CeldaInspeccion::iniciarTurno() ya la usa: revisen cómo la llama.
    //  - Calibrable es una capacidad, no un dispositivo: ¿debe tener atributos?
    //  - ¿Qué necesita el destructor de una clase pensada para usarse por puntero?
};

}  // namespace calidad
