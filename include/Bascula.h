#pragma once
#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad  
{

    class Bascula : public Dispositivo, public Calibrable  
    {

    private:
    std::string nombre_;
    double desfase_ = 0.4;
    public:
    explicit Bascula(const std::string& id);

    bool inspeccionar(const Pieza& pieza) const override;
    const std::string& descripcion() const override;
    bool calibrar() override;
    double getDesfase() const;
    };
}  
