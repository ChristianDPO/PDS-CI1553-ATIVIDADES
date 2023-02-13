#include "Circulo.hpp"
#include "DimensaoNulaException.hpp"

#include <cmath>

namespace christian{

Circulo::Circulo(const double raio):Forma{}{
    if(raio <= 0)
        throw DimensaoNulaException{};
    this->raio = raio;
}

std::ostream& operator<<(std::ostream& stream, const Circulo& circulo){
    stream << "=== Dados do Circulo ===\n";
    stream << "Raio: " << circulo.getRaio() << '\n';
    stream << "Área: " << circulo.calcularArea() << '\n';
    stream << "========================\n";
    return stream;
}


void Circulo::setRaio(const double raio){
    if(raio <= 0)
        throw DimensaoNulaException{}; 
    this->raio = raio;
}

double Circulo::getRaio() const{
    return this->raio;
}

double Circulo::calcularArea() const{
    return 2*M_PI*this->raio;
}

}