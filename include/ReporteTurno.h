#pragma once

#include <string>

namespace calidad {

class ReporteTurno {

private:
    int piezasInspeccionadas_;
    int piezasAceptadas_;
    int piezasRechazadas_;

public:
    explicit ReporteTurno();

    void registrarAceptada();
    void registrarRechazada();

    int inspeccionadas() const;
    int aceptadas() const;
    int rechazadas() const;

    bool operator==(const ReporteTurno& otro) const;
};

}  // namespace calidad