#include <iostream>
#include <map>

#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "SensorTemperatura.h"
#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "ReporteTurno.h"
#include "InspectorDureza.h"

int main() {
    using namespace calidad;

    // Crear los dispositivos
    Bascula bascula("B-01");
    CalibradorLaser laser("L-01");
    SensorTemperatura temperatura("T-01");
    CamaraVision camara("V-01");
    InspectorDureza dureza("Z-01");

    // Crear la celda de inspeccion
    CeldaInspeccion celda;

    // Agregar dispositivos a la celda
    celda.agregarDispositivo(&bascula);
    celda.agregarDispositivo(&laser);
    celda.agregarDispositivo(&temperatura);
    celda.agregarDispositivo(&camara);
      celda.agregarDispositivo(&dureza);

    // Iniciar turno y calibrar dispositivos
    celda.iniciarTurno();

    // Obtener las piezas del turno
    std::vector<Pieza> piezas = piezasDelTurno();

    // Inspeccionar todas las piezas
    for (const Pieza& pieza : piezas) {
        celda.procesar(pieza);
    }

    // Crear el reporte esperado
    ReporteTurno esperado(6, 6, {
        {"B-01", 2},
        {"L-01", 2},
        {"T-01", 2},
        {"V-01", 2}
    });

    // Mostrar reporte final
    std::cout << "\n=== REPORTE FINAL ===\n";
    std::cout << celda.reporte();

    // Comparar reporte real con reporte esperado
    if (celda.reporte() == esperado) {
        std::cout << "Reporte correcto\n";
    } else {
        std::cout << "Reporte incorrecto\n";
    }

    return 0;
}