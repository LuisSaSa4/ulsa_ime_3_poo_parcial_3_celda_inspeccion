#pragma once
#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class Bascula : public Dispositivo, public Calibrable  {

private:
std::string nombre_;
double desfase_ = 0.4;
public:

bool inspeccionar(const Pieza& pieza) const override;
const std::string& descripcion() const override;
bool calibrar() const override;
double getDesfase();
};
}  // namespace calidad
