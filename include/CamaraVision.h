#pragma once

#include "Dispositivo.h"

namespace calidad {

class CamaraVision final : public Dispositivo {

public:
    explicit CamaraVision(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;

    const std::string& descripcion() const override;
};

} // namespace calidad