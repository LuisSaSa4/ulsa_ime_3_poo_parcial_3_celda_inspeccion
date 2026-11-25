#include "CalibradorLaser.h"

namespace calidad{

CalibradorLaser::CalibradorLaser(const std::string& id_): Dispositivo(id_){

};

bool CalibradorLaser::inspeccionar(const Pieza& pieza) const {
double largoMedido = pieza.largo() + desfase_;
return largoMedido >= 49.5 && largoMedido <= 50.5;
}

const std::string& CalibradorLaser::descripcion() const {
static const std::string nombre = "Calibrador Laser";
return nombre;
}

bool CalibradorLaser::calibrar(){
desfase_ = 0;
return true;
}

double CalibradorLaser::getDesfase()const{
    return desfase_;
}

}