#include "ReporteTurno.h"

namespace calidad {

ReporteTurno::ReporteTurno()
    : piezasInspeccionadas_(0),
      piezasAceptadas_(0),
      piezasRechazadas_(0) {
}

void ReporteTurno::registrarAceptada() {
    piezasInspeccionadas_++;
    piezasAceptadas_++;
}

void ReporteTurno::registrarRechazada() {
    piezasInspeccionadas_++;
    piezasRechazadas_++;
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

bool ReporteTurno::operator==(const ReporteTurno& otro) const {
    return piezasInspeccionadas_ == otro.piezasInspeccionadas_ &&
           piezasAceptadas_ == otro.piezasAceptadas_ &&
           piezasRechazadas_ == otro.piezasRechazadas_;
}

}  // namespace calidad