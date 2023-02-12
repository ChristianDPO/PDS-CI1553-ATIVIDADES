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
#include "Pessoa.hpp"
#include "Motorista.hpp"
#include "ModelSistemaFrota.hpp"

int main(){

	std::list<frota::Veiculo *>* const lista_veiculos{new std::list<frota::Veiculo *>};
	std::list<frota::Motorista *>* const lista_motoristas{new std::list<frota::Motorista *>};

	frota::ModelSistemaFrota modelo{lista_motoristas, lista_veiculos};

	modelo.cadastrarVeiculo("Yamaha", 2000, "CCC3C33", "3CCCCCCCCC3333333", 
		"33333333333", 8000.50, frota::EnumTipoMoto::PADRAO
	);

	modelo.cadastrarVeiculo("Pegout", 2018, "AAA0A00", "0AAAAAAAAA0000000", 
		"11111111111", 22437.50, frota::EnumTipoCarro::ENTREGA
	);
	
	modelo.cadastrarVeiculo("Volkswagen", 2018, "DDD4D44", "4DDDDDDDDD4444444", 
		"00000000004", 22000.50, frota::EnumTipoCarro::ENTREGA, 100
	);

	modelo.cadastrarVeiculo("Mercedez", 2023, "BBB1B11", "1BBBBBBBBB1111111", 
		"22222222222", 700000.50, frota::EnumTipoCaminhao::CARRETA, 450
	);

	// frota::Motorista* m1{new frota::Motorista{"João", "00011111111", 23, "001234567", 60, 25.50}};

	// m1->imprimeDadosPessoa();
	
	// frota::Carro* car1{new frota::Carro{"Pegout", 2018, "AAA0A00", "0AAAAAAAAA0000000", 
	// 	"11111111111", 22437.50, frota::EnumTipoCarro::ENTREGA
	// }};
	
	// frota::Caminhao* cam1{new frota::Caminhao{"Mercedez", 2023, "BBB1B11", "1BBBBBBBBB1111111", 
	// 	"22222222222", 700000.50, frota::EnumTipoCaminhao::CARRETA, 450
	// }};

	// frota::Moto* mot1{new frota::Moto{"Yamaha", 2000, "CCC3C33", "3CCCCCCCCC3333333", 
	// 	"33333333333", 8000.50, frota::EnumTipoMoto::PADRAO
	// }};

	// frota::Van* van1{new frota::Van{"Volkswagen", 2018, "DDD4D44", "4DDDDDDDDD4444444", 
	// 	"00000000004", 22000.50, frota::EnumTipoCarro::ENTREGA, 100
	// }};

	std::list<frota::Veiculo *>::iterator it;
	for(it = lista_veiculos->begin(); it != lista_veiculos->end(); ++it){
		(*it)->imprimeDadosVeiculo();
	}
	return 0;
}
