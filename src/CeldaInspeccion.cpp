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
        if (Calibrable* c = dynamic_cast<Calibrable*>(d)) {
            std::cout << "Calibrando " << d->id()
                      << " (" << d->descripcion() << ") ... "
                      << (c->calibrar() ? "OK" : "FALLA") << '\n';
        }
    }
}

bool CeldaInspeccion::procesar(const Pieza& pieza) {
    bool aceptada = true;

    std::cout << "\n=== Inspeccionando pieza " << pieza.id() << " ===\n";

    for (Dispositivo* d : dispositivos_) {
        if (d == nullptr) {
            continue;
        }

        bool resultado = d->inspeccionar(pieza);

        std::cout << "Dispositivo " << d->id()
                  << " (" << d->descripcion() << "): "
                  << (resultado ? "Aceptada" : "Rechazada") << '\n';

        if (!resultado) {
            aceptada = false;
            reporte_.registrarRechazo(d->id());
        }
    }

    reporte_.registrarPieza(aceptada);

    std::cout << "Resultado final de la pieza " << pieza.id()
              << ": " << (aceptada ? "Aceptada" : "Rechazada") << '\n';

    return aceptada;
}

const ReporteTurno& CeldaInspeccion::reporte() const {
    return reporte_;
}

}  // namespace calidad