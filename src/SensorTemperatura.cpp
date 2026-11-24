
#include "SensorTemperatura.h"

namespace calidad {

SensorTemperatura::SensorTemperatura(const std::string& id)
    : Dispositivo(id) {
}

bool SensorTemperatura::inspeccionar(const Pieza& pieza) const {
    return pieza.temperatura() >= 20.0 &&
           pieza.temperatura() <= 35.0;
}

const std::string& SensorTemperatura::descripcion() const {
    static const std::string nombre = "Sensor de temperatura";
    return nombre;
}

}  // namespace calidad
