#pragma once

#include <map>
#include <string>
#include <iostream>

namespace calidad {

class ReporteTurno {

private:
    int piezasInspeccionadas_;
    int piezasAceptadas_;
    int piezasRechazadas_;
    std::map<std::string, int> rechazosPorDispositivo_;

public:
    ReporteTurno();

    ReporteTurno(int aceptadas, int rechazadas,
                 std::map<std::string, int> rechazosPorDispositivo);

    void registrarPieza(bool aceptada);
    void registrarRechazo(const std::string& dispositivo);

    int inspeccionadas() const;
    int aceptadas() const;
    int rechazadas() const;

    const std::map<std::string, int>& rechazosPorDispositivo() const;

    bool operator==(const ReporteTurno& otro) const;

    friend std::ostream& operator<<(std::ostream& os,
                                   const ReporteTurno& reporte);
};

}  // namespace calidad