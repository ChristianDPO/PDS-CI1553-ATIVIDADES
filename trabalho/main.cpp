#include <iostream>
#include <iomanip>

#include "Carro.hpp"

int main(){

	frota::Carro carro{"Pegout", 2018, "AAA1234", "9BRBLWHEXG0107721", 12345678900, 700000.50};

	std::cout<<std::fixed<<std::setprecision(2)<< carro.calcularIPVA() << std::endl;

	return 0;
}
