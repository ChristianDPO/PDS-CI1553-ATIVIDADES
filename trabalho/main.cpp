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
#include "ViewSistemaFrota.hpp"

int main(){

	//Instancia do Modelo
	frota::ModelSistemaFrota* modelo{new frota::ModelSistemaFrota};

	//Instancia da View
	frota::ViewSistemaFrota view{modelo};

	//Carregamento de dados
	modelo->cadastrarVeiculo("Yamaha", 2000, "CCC3C33", "3CCCCCCCCC3333333", 
		"33333333333", 8000.50, frota::EnumTipoMoto::PADRAO
	);
	modelo->cadastrarVeiculo("Pegout", 2018, "AAA0A00", "0AAAAAAAAA0000000", 
		"11111111111", 22437.50, frota::EnumTipoCarro::ENTREGA
	);
	modelo->cadastrarVeiculo("Volkswagen", 2018, "DDD4D44", "4DDDDDDDDD4444444", 
		"00000000004", 22000.50, frota::EnumTipoCarro::ENTREGA, 100
	);
	modelo->cadastrarVeiculo("Mercedez", 2023, "BBB1B11", "1BBBBBBBBB1111111", 
		"22222222222", 700000.50, frota::EnumTipoCaminhao::CARRETA, 450
	);

	//testar veiculo ja cadastrado
	// modelo->cadastrarVeiculo("Mercedez", 2023, "BBB1B11", "1BBBBBBBBB1111111", 
	// 	"22222222222", 700000.50, frota::EnumTipoCaminhao::CARRETA, 450
	// );

	modelo->cadastrarMotorista("João", "00011111111", 23, "001234567", 60, 25.50);
	modelo->cadastrarMotorista("Maria", "00022222222", 30, "007654321", 100, 1000);

	//teste motorista ja cadastrado
	//modelo->cadastrarMotorista("João", "00011111111", 23, "001234567", 60, 25.50);

	// const std::list<frota::Motorista *>* const lista_motoristas{modelo->getMotoristas()};
	// std::list<frota::Motorista *>::const_iterator it_mot;
	// for(it_mot = lista_motoristas->begin(); it_mot != lista_motoristas->end(); ++it_mot){
	// 	(*it_mot)->imprimeDadosPessoa();
	// }

	// const std::list<frota::Veiculo *>* const lista_veiculos{modelo->getVeiculos()};
	// std::list<frota::Veiculo *>::const_iterator it;
	// for(it = lista_veiculos->begin(); it != lista_veiculos->end(); ++it){
	// 	(*it)->imprimeDadosVeiculo();
	// }

	EnumTipoOperacao op;

	do{
		op = view.menuPrincipal();
		view.realizaOperacao(op);
	} while(op != frota::EnumTipoOperacao::SAIR);

	return 0;
}
