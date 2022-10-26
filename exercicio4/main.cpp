#include<iostream>

#include "Retangulo.hpp"

int main(){
	float base;
	float altura;

	std::cout << "Digite a medida da base do retangulo: ";
	std::cin >> base;
	std::cout << "Digite a medida da altura do retangulo: ";
	std::cin >> altura;

	Retangulo ret(base, altura);

	std::cout << "Base: " << ret.getBase() << "\n" << "Altura: " <<  ret.getAltura() << std::endl;
	std::cout << "Area do Retangulo: " << ret.getArea() << "\n" << "Perimetro do Retangulo: " <<  ret.getPerimetro() << std::endl;

	return 0;
}
