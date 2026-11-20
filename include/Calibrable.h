#pragma once

namespace calidad {

class Calibrable {
private:
    bool calibrable;
public:
    virtual bool calibrar() const = 0;
    // TODO (equipo): definan la interfaz de los dispositivos que se pueden calibrar.
    //  - CeldaInspeccion::iniciarTurno() ya la usa: revisen cómo la llama.
    //  - Calibrable es una capacidad, no un dispositivo: ¿debe tener atributos?
    //  - ¿Qué necesita el destructor de una clase pensada para usarse por puntero?
};

}  // namespace calidad
