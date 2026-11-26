// Experimento 1: memoria y object slicing bajo herencia.
// Programa independiente: no usa las clases del proyecto.


#include <iostream>
using namespace std;

// Primera parte: clases sin metodo virtual
class BaseSimple {
public:
    int datoBase;
};

class DerivadaSimple : public BaseSimple {
public:
    int datoDerivado;
};

// Segunda parte: clases con metodo virtual
class Base {
public:
    int datoBase;

    virtual void mostrar() const {
        cout << "Metodo de Base" << endl;
    }
};

class Derivada : public Base {
public:
    int datoDerivado;

    void mostrar() const override {
        cout << "Metodo de Derivada" << endl;
    }
};

// Recibe un objeto Base por valor
void recibirPorValor(Base objeto) {
    objeto.mostrar();
}

int main() {
    cout << "=== Experimento 1: Memoria y object slicing ===" << endl;

    cout << "\n1. Clases sin metodo virtual" << endl;
    cout << "Tamano de BaseSimple: " << sizeof(BaseSimple) << " bytes" << endl;
    cout << "Tamano de DerivadaSimple: " << sizeof(DerivadaSimple) << " bytes" << endl;

    cout << "\n2. Clases con metodo virtual" << endl;
    cout << "Tamano de Base: " << sizeof(Base) << " bytes" << endl;
    cout << "Tamano de Derivada: " << sizeof(Derivada) << " bytes" << endl;

    cout << "\n3. Prueba de object slicing" << endl;

    Derivada objetoDerivado;
    recibirPorValor(objetoDerivado);

    return 0;
}
