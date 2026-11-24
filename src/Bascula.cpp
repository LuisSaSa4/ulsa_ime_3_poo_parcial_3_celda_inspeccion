#include "Bascula.h"

namespace calidad
{
    Bascula::Bascula(const std::string& id)
    : Dispositivo(id) {
    }

    bool Bascula::inspeccionar(const Pieza& pieza) const {
    const double pesoMedido = pieza.peso() + desfase_;
    return pesoMedido >= 10.0 && pesoMedido <= 15.0;
    }

    const std::string& Bascula::descripcion() const {
    static const std::string nombre = "Bascula";
    return nombre;
    }

    bool Bascula::calibrar() {
    desfase_ = 0.0;
    return true;
    }

    double Bascula::getDesfase() const {
    return desfase_;
    }

}