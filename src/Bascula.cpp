#include "Bascula.h"

namespace calidad{


bool Bascula::inspeccionar(const Pieza& pieza) const{
if(pieza.peso() > 15.0){

}
}

bool Bascula::calibrar() const{
    return true;
}
}