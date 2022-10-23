#include<iostream>

#include "Retangulo.hpp"

int main(){
	Retangulo ret;
    float area;
    float perimetro;

	std::cout << "Digite a medida da base do retangulo: ";
	std::cin >> ret.base;
	std::cout << "Digite a medida da altura do retangulo: ";
	std::cin >> ret.altura;

    area = ret.calcularArea(ret.base, ret.altura);
    perimetro = ret.calcularPerimetro(ret.base, ret.altura);

	std::cout << "Area do Retangulo: " << area << "\n" << "Perimetro do Retangulo: " <<  perimetro << std::endl;

	return 0;
}
