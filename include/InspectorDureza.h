#pragma once

#include "Dispositivo.h"

namespace calidad {

class InspectorDureza : public Dispositivo {
public:
    explicit InspectorDureza(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;

    const std::string& descripcion() const override;
};

}