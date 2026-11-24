#pragma once

#include <string>

namespace calidad {

class ReporteTurno {
<<<<<<< HEAD

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
=======
    public:
explicit ReporteTurno();
};
}  // namespace calidad
>>>>>>> 02f69c27ada1b856816a8431141a977889deaea4
