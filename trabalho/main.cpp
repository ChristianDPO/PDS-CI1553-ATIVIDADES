#include <iostream>
#include <list>
#include <iomanip>

#include "Veiculo.hpp"
#include "Carro.hpp"
#include "EnumTipoCarro.hpp"
#include "Caminhao.hpp"
#include "EnumTipoCaminhao.hpp"
#include "Moto.hpp"
#include "EnumTipoMoto.hpp"
#include "Van.hpp"

int main(){

	std::list<frota::Veiculo *> lista_veiculos;
	std::list<frota::Veiculo *>* pont_lista{&lista_veiculos};

	frota::Carro* car1{new frota::Carro{"Pegout", 2018, "AAA0A00", "9BRBLWHEXG0107721", 
		11111111111, 22000.50, frota::EnumTipoCarro::ENTREGA
	}};
	
	frota::Caminhao* cam1{new frota::Caminhao{"Mercedez", 2023, "BBB1B11", "5ABCDEFGHJ1234567", 
		22222222222, 700000.50, frota::EnumTipoCaminhao::CARRETA, 450
	}};

	frota::Moto* mot1{new frota::Moto{"Yamaha", 2000, "CCC3C33", "7ABCDEFGHJ1234567", 
		33333333333, 8000.50, frota::EnumTipoMoto::PADRAO
	}};

	frota::Van* van1{new frota::Van{"Volkswagen", 2018, "DDD4D44", "4ABCDEFGHJ1234567", 
		44444444444, 22000.50, frota::EnumTipoCarro::ENTREGA, 100
	}};

	pont_lista->push_back(car1);
	pont_lista->push_back(van1);
	pont_lista->push_back(cam1);
	pont_lista->push_back(mot1);

	std::list<frota::Veiculo *>::iterator it;

	for(it = pont_lista->begin(); it != pont_lista->end(); ++it){
		(*it)->imprimeDadosVeiculo();
	}
	return 0;
}
