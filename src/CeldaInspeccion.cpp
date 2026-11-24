#include "CeldaInspeccion.h"

#include <iostream>

#include "Calibrable.h"

namespace calidad {

void CeldaInspeccion::agregarDispositivo(Dispositivo* d) {
    if (d != nullptr) {
        dispositivos_.push_back(d);
    }
}

void CeldaInspeccion::iniciarTurno() {
    std::cout << "=== Inicio de turno ===\n";

    for (Dispositivo* d : dispositivos_) {
        // ¿Este dispositivo también es Calibrable?
        if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
            std::cout << "Calibrando " << d->id()
                      << " (" << d->descripcion() << ") ... "
                      << (c->calibrar() ? "OK" : "FALLA") << '\n';
        }
    }
}

bool CeldaInspeccion::procesar(const Pieza& pieza) {
    for (Dispositivo* d : dispositivos_) {
        if (!d->inspeccionar(pieza)) {
            reporte_.registrarRechazada();

            std::cout << "Pieza " << pieza.id()
                      << ": Rechazada por "
                      << d->descripcion() << '\n';

            return false;
        }
    }

    reporte_.registrarAceptada();

    std::cout << "Pieza " << pieza.id()
              << ": Aceptada\n";

    return true;
}

const ReporteTurno& CeldaInspeccion::reporte() const {
    return reporte_;
}

}  // namespace calidad