
#include "DetectorExtra.h"

namespace calidad {

DetectorExtra::DetectorExtra(const std::string& id)
    : Dispositivo(id) {}

bool DetectorExtra::inspeccionar(const Pieza& pieza) const {
    return pieza.defectos() == 0;
}

const std::string& DetectorExtra::descripcion() const {
    static const std::string nombre = "Detector extra";
    return nombre;
}

}  // namespace calidad
