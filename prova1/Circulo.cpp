#include "Circulo.hpp"

Circulo::Circulo(const float raio)
    :raio{raio}{
}

float Circulo::calcularArea() const{
    return raio*raio*3.14;
}