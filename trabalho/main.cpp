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

	//Carregamento previo de alguns dados

	//Motos
	modelo->cadastrarVeiculo("Modelo Moto 1", 2000, "AAA0A00", "0AAAAAAAAA0000000", 
		"11111111111", 1000.50, frota::EnumTipoMoto::SCOOTER
	);
	modelo->cadastrarVeiculo("Modelo Moto 2", 2004, "BBB1B11", "1BBBBBBBBB1111111", 
		"22222222222", 2000.50, frota::EnumTipoMoto::PADRAO
	);
	modelo->cadastrarVeiculo("Modelo Moto 3", 2005, "CCC3C33", "3CCCCCCCCC3333333", 
		"33333333333", 3500.50, frota::EnumTipoMoto::OFFROAD
	);
	//Carros
	modelo->cadastrarVeiculo("Modelo Carro 1", 2001, "DDD4D44", "4DDDDDDDDD4444444", 
		"44444444444", 10000.50, frota::EnumTipoCarro::ENTREGA
	);
	modelo->cadastrarVeiculo("Modelo Carro 2", 2005, "EEE5E55", "5EEEEEEEEE5555555", 
		"55555555555", 20000.50, frota::EnumTipoCarro::VIAGEM
	);
	//Vans
	modelo->cadastrarVeiculo("Modelo Van 1", 2006, "FFF6F66", "6FFFFFFFFF6666666", 
		"66666666666", 10000.50, frota::EnumTipoCarro::ENTREGA, 150
	);
	modelo->cadastrarVeiculo("Modelo Van 2", 2007, "GGG7G77", "7GGGGGGGGG7777777", 
		"77777777777", 20000.50, frota::EnumTipoCarro::VIAGEM, 350
	);
	//Caminhoes
	modelo->cadastrarVeiculo("Modelo Caminhao 1", 2008, "HHH8H88", "8HHHHHHHHH8888888", 
		"88888888888", 20000.50, frota::EnumTipoCaminhao::FRETE, 1500
	);
	modelo->cadastrarVeiculo("Modelo Caminhao 2", 2009, "III9I99", "9IIIIIIIII9999999", 
		"99999999999", 800000, frota::EnumTipoCaminhao::CARRETA, 20000
	);

	modelo->cadastrarMotorista("João", "11111111111", 23, "000111111", 60, 25.50);
	modelo->associarVeiculoMotorista("AAA0A00", "11111111111");
	modelo->associarVeiculoMotorista("DDD4D44", "11111111111");
	modelo->associarVeiculoMotorista("FFF6F66", "11111111111");
	modelo->associarVeiculoMotorista("HHH8H88", "11111111111");

	modelo->cadastrarMotorista("Maria", "22222222222", 30, "000222222", 100, 1000);
	modelo->associarVeiculoMotorista("AAA0A00", "22222222222");
	modelo->associarVeiculoMotorista("CCC3C33", "22222222222");
	modelo->associarVeiculoMotorista("EEE5E55", "22222222222");
	modelo->associarVeiculoMotorista("GGG7G77", "22222222222");
	modelo->associarVeiculoMotorista("III9I99", "22222222222");

	// Execucao do sistema (controller)
	EnumTipoOperacao op;

	do{
		op = view.menuPrincipal();
		view.realizaOperacao(op);
	} while(op != frota::EnumTipoOperacao::SAIR);

	return 0;
}
