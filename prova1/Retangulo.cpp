#include "Retangulo.hpp"

Retangulo::Retangulo(const float largura, const float altura)
    : largura{largura}, altura{altura}{
}

float Retangulo::calcularArea() const{
    return largura*altura;
}