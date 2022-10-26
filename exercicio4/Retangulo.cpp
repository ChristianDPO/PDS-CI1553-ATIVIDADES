#include "Retangulo.hpp"

Retangulo::Retangulo()
    :base{0}, altura{0}, area{-1}, perimetro{-1}{
}

Retangulo::Retangulo(float novaBase, float novaAltura)
    :base(novaBase), altura(novaAltura), area{-1}, perimetro{-1}{
}

float Retangulo::getBase(){
    return base;
}

void Retangulo::setBase(float novaBase){
    base = novaBase;
}

float Retangulo::getAltura(){
    return altura;
}

void Retangulo::setAltura(float novaAltura){
    altura = novaAltura;
}


float Retangulo::getArea(){
    if(base > 0 && altura > 0)
        area = base*altura;

    return area;
}

float Retangulo::getPerimetro(){
    if(base > 0 && altura > 0)
        perimetro = 2*(base+altura);
    
    return perimetro;
}