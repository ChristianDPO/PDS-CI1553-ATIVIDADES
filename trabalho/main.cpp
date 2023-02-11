#include <iostream>
#include <list>
#include <iomanip>

#include "Veiculo.hpp"
#include "EnumTipoCarro.hpp"
#include "Carro.hpp"

int main(){

	std::list<frota::Veiculo *> lista_veiculos;
	std::list<frota::Veiculo *>* pont_lista{&lista_veiculos};

	frota::Carro* carro{new frota::Carro{"Pegout", 2018, "AAA1234", "9BRBLWHEXG0107721", 
		12345678900, 700000.50, frota::EnumTipoCarro::ENTREGA
	}};

	pont_lista->push_back(carro);

	std::list<frota::Veiculo *>::iterator it;

	for(it = pont_lista->begin(); it != pont_lista->end(); ++it){
		(*it)->imprimeDadosVeiculo();
	}
	return 0;
}
