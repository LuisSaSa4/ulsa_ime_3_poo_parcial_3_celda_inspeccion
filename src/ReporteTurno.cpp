#include "ReporteTurno.h"

namespace calidad {

ReporteTurno::ReporteTurno()
    : piezasInspeccionadas_(0),
      piezasAceptadas_(0),
      piezasRechazadas_(0) {
}

ReporteTurno::ReporteTurno(int aceptadas, int rechazadas,
                           std::map<std::string, int> rechazosPorDispositivo)
    : piezasInspeccionadas_(aceptadas + rechazadas),
      piezasAceptadas_(aceptadas),
      piezasRechazadas_(rechazados),
      rechazosPorDispositivo_(rechazosPorDispositivo) {
}

void ReporteTurno::registrarPieza(bool aceptada) {
    piezasInspeccionadas_++;

    if (aceptada) {
        piezasAceptadas_++;
    } else {
        piezasRechazadas_++;
    }
}

void ReporteTurno::registrarRechazo(const std::string& dispositivo) {
    rechazosPorDispositivo_[dispositivo]++;
}

int ReporteTurno::inspeccionadas() const {
    return piezasInspeccionadas_;
}

int ReporteTurno::aceptadas() const {
    return piezasAceptadas_;
}

int ReporteTurno::rechazadas() const {
    return piezasRechazadas_;
}

const std::map<std::string, int>& ReporteTurno::rechazosPorDispositivo() const {
    return rechazosPorDispositivo_;
}

bool ReporteTurno::operator==(const ReporteTurno& otro) const {
    return piezasInspeccionadas_ == otro.piezasInspeccionadas_ &&
           piezasAceptadas_ == otro.piezasAceptadas_ &&
           piezasRechazadas_ == otro.piezasRechazadas_ &&
           rechazosPorDispositivo_ == otro.rechazosPorDispositivo_;
}

std::ostream& operator<<(std::ostream& os, const ReporteTurno& reporte) {
    os << "Piezas inspeccionadas: " << reporte.piezasInspeccionadas_ << '\n';
    os << "Piezas aceptadas: " << reporte.piezasAceptadas_ << '\n';
    os << "Piezas rechazadas: " << reporte.piezasRechazadas_ << '\n';

    os << "Rechazos por dispositivo:\n";

    for (const auto& rechazo : reporte.rechazosPorDispositivo_) {
        os << "  " << rechazo.first << ": " << rechazo.second << '\n';
    }

    return os;
}

}  // namespace calidad
