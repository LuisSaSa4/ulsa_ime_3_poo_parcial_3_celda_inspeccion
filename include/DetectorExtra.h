
#pragma once

#include "Dispositivo.h"

namespace calidad {

class DetectorExtra : public Dispositivo {
public:
    explicit DetectorExtra(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;

    const std::string& descripcion() const override;
};

}  // namespace calidad
