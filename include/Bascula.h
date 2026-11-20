#pragma once
#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class Bascula : public Dispositivo, public Calibrable  {

private:
std::string nombre_;
double desfase_;

public:

bool inspeccionar(const Pieza& pieza) const override;
const std::string& descripcion() const override;

};
}  // namespace calidad
