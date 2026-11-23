#include "CalibradorLaser.h"

namespace calidad{

CalibradorLaser::CalibradorLaser(const std::string& id_, const std::string& nombre_): Dispositivo(id_), nombre_(nombre_){

};

bool CalibradorLaser::inspeccionar(const Pieza& pieza) const{
if(pieza.largo() <= 49.5 || pieza.largo() >= 50.50){
return false;
}
else {
return true;
}
}

double CalibradorLaser::getDesfase(){
    return desfase_;
}

void CalibradorLaser::modificarDesfase(){
desfase_ = 0;
}

bool CalibradorLaser::calibrar() const{
modificarDesfase;
return true;
}



}