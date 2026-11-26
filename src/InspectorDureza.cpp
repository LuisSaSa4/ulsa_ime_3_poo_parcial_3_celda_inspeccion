#include "InspectorDureza.h"

namespace calidad {

InspectorDureza::InspectorDureza(const std::string& id)
    : Dispositivo(id) {}

bool InspectorDureza::inspeccionar(const Pieza& pieza) const {
    return pieza.dureza() >= 55;
}

const std::string& InspectorDureza::descripcion() const {
    static const std::string nombre = "Inspector Dureza";
    return nombre;
}

}