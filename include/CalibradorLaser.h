#pragma once
#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class CalibradorLaser : public Dispositivo, public Calibrable  {

private:

double desfase_ =-0.3;
public:

explicit CalibradorLaser(const std::string& id_);

bool inspeccionar(const Pieza& pieza) const override;
const std::string& descripcion() const override;
bool calibrar() override;
double getDesfase() const;
};
}  // namespace calidad