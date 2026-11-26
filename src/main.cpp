
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>

#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "SensorTemperatura.h"
#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "ReporteTurno.h"

int main() {
    using namespace calidad;

    // Crear los dispositivos
    Bascula bascula("B-01");
    CalibradorLaser laser("L-01");
    SensorTemperatura temperatura("T-01");
    CamaraVision camara("V-01");

    // Crear la celda de inspeccion
    CeldaInspeccion celda;

    // Agregar dispositivos a la celda
    celda.agregarDispositivo(&bascula);
    celda.agregarDispositivo(&laser);
    celda.agregarDispositivo(&temperatura);
    celda.agregarDispositivo(&camara);

    // Iniciar turno y calibrar dispositivos
    celda.iniciarTurno();

    int opcion;
    std::cout << "\nSelecciona el modo de inspeccion:\n";
    std::cout << "1. Turno original\n";
    std::cout << "2. Turno aleatorio\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;

    std::vector<Pieza> piezas;

    if (opcion == 2) {
        // Generador aleatorio con semilla fija
        std::mt19937 generador(12345);

        std::uniform_int_distribution<int> peso(80, 170);
        std::uniform_int_distribution<int> largo(485, 520);
        std::uniform_int_distribution<int> temperatura(150, 420);
        std::uniform_int_distribution<int> defectos(0, 3);
        std::uniform_int_distribution<int> dureza(40, 65);

        // Crear 12 piezas aleatorias
        for (int i = 1; i <= 12; i++) {
            std::string id = "R-";
            if (i < 10) {
                id += "0";
            }
            id += std::to_string(i);

            Pieza pieza(
                id,
                peso(generador) / 10.0,
                largo(generador) / 10.0,
                temperatura(generador) / 10.0,
                defectos(generador),
                dureza(generador)
            );

            piezas.push_back(pieza);
        }

        std::cout << "\n=== TURNO ALEATORIO ===\n";
    }
    else {
        // Usar las 12 piezas originales
        piezas = piezasDelTurno();
        std::cout << "\n=== TURNO ORIGINAL ===\n";
    }

    // Inspeccionar todas las piezas
    for (const Pieza& pieza : piezas) {
        celda.procesar(pieza);
    }

    // Mostrar reporte final
    std::cout << "\n=== REPORTE FINAL ===\n";
    std::cout << celda.reporte();

    // Comparar solamente el turno original
    if (opcion != 2) {
        ReporteTurno esperado(6, 6, {
            {"B-01", 2},
            {"L-01", 2},
            {"T-01", 2},
            {"V-01", 2}
        });

        if (celda.reporte() == esperado) {
            std::cout << "Reporte correcto\n";
        } else {
            std::cout << "Reporte incorrecto\n";
        }
    }
    else {
        std::cout << "Turno aleatorio finalizado\n";
    }

    return 0;
}
