// Experimento 2: destructor virtual vs. no virtual al destruir por puntero base.
// Programa independiente: no usa las clases del proyecto.


#include <iostream>
using namespace std;

// Primera prueba: destructor NO virtual
class BaseSimple {
public:
    virtual void mostrar() {
        cout << "Metodo de BaseSimple" << endl;
    }

    ~BaseSimple() {
        cout << "Destructor de BaseSimple" << endl;
    }
};

class DerivadaSimple : public BaseSimple {
public:
    ~DerivadaSimple() {
        cout << "Destructor de DerivadaSimple" << endl;
    }
};

// Segunda prueba: destructor virtual
class BaseVirtual {
public:
    virtual void mostrar() {
        cout << "Metodo de BaseVirtual" << endl;
    }

    virtual ~BaseVirtual() {
        cout << "Destructor de BaseVirtual" << endl;
    }
};

class DerivadaVirtual : public BaseVirtual {
public:
    ~DerivadaVirtual() {
        cout << "Destructor de DerivadaVirtual" << endl;
    }
};

int main() {
    cout << "=== Destructor NO virtual ===" << endl;

    BaseSimple* objeto1 = new DerivadaSimple();
    delete objeto1;

    cout << "\n=== Destructor VIRTUAL ===" << endl;

    BaseVirtual* objeto2 = new DerivadaVirtual();
    delete objeto2;

    return 0;
}
