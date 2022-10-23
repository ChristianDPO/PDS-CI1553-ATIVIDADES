#include "Retangulo.hpp"

float Retangulo::calcularArea(float base, float altura){
    return base*altura;
}

float Retangulo::calcularPerimetro(float base, float altura){
    return 2*(base+altura);
}