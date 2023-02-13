#include "Retangulo.hpp"
#include "DimensaoNulaException.hpp"

namespace christian{

Retangulo::Retangulo(const double altura, const double largura):Forma{}{
    if(altura <= 0 || largura <= 0)
        throw DimensaoNulaException{};
    this->altura = altura;
    this->largura = largura;
}

std::ostream& operator<<(std::ostream& stream, const Retangulo& retangulo){
    stream << "=== Dados do Retangulo ===\n";
    stream << "Altura: " << retangulo.getAltura() << '\n';
    stream << "Largura: " << retangulo.getLargura() << '\n';
    stream << "Área: " << retangulo.calcularArea() << '\n';
    stream << "========================\n";
    return stream;
}

void Retangulo::setAltura(const double altura){
    this->altura = altura;
}

void Retangulo::setLargura(const double largura){
    if(largura <= 0)
        throw DimensaoNulaException{};
    this->largura = largura;
}

double Retangulo::getAltura() const{
    return this->altura;
}

double Retangulo::getLargura() const{
    if(altura <= 0)
        throw DimensaoNulaException{};
    return this->largura;
}

double Retangulo::calcularArea() const{
    return this->largura*this->altura;
}

}