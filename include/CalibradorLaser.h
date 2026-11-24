#pragma once
#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class CalibradorLaser : public Dispositivo, public Calibrable  {

private:
const std::string& nombre_;
double desfase_ =-0.3;
public:

CalibradorLaser(const std::string& nombre_, const std::string& id_);

bool inspeccionar(Pieza& pieza) const override;
const std::string& descripcion() const override;
bool calibrar() const override;
double getDesfase() ;
void modificarDesfase();
~CalibradorLaser() override;
};
}  // namespace calidad