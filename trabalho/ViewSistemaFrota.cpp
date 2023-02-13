#include "ViewSistemaFrota.hpp"

#include <iostream>

using namespace frota;

ViewSistemaFrota::ViewSistemaFrota(ModelSistemaFrota* const modelo)
    :modelo{modelo}{
}

ViewSistemaFrota::~ViewSistemaFrota(){
    std::cout << "&&& Desalocando ViewSistemaFrota\n";
    delete this->modelo;
}

/**
 * Tela do Menu principal
 * @return EnumTipoOperacao Operacao selcionada pelo usuario
 */
EnumTipoOperacao ViewSistemaFrota::menuPrincipal() const {
    
    unsigned short int op;

    std::cout << "====== Bem Vindo ao Sistema de Cadastro de Frotas  ======\n";
    std::cout << "====== Digite o numero de uma das operações abaixo ======\n";
    std::cout << "0 - Visualizar Veiculos\n";
    std::cout << "1 - Visualizar Motoristas\n";
    std::cout << "2 - Cadastrar Veiculos\n";
    std::cout << "3 - Cadastrar Motoristas\n";
    std::cout << "7 - Sair\n";

    std::cout << "====== Operacao: ";
    std::cin >> op;

    if(op < 0 || op > 7)
        return EnumTipoOperacao::INVALIDA;
    
    system("clear");
    
    return (EnumTipoOperacao) op;

}


/**
 * Imprime na tela os veiculos atuiais do sistema
 */
void ViewSistemaFrota::visualizarVeiculos() const {
	
    const std::list<frota::Veiculo *>* const lista_veiculos{this->modelo->getVeiculos()};
	std::list<frota::Veiculo *>::const_iterator it;
	for(it = lista_veiculos->begin(); it != lista_veiculos->end(); ++it){
		std::cout << std::endl;
        (*it)->imprimeDadosVeiculo();
	}
    std::cout << std::endl;
}
/**
 * Imprime na tela os motoristas atuiais do sistema
 */
void ViewSistemaFrota::visualizarMotoristas() const{

	const std::list<frota::Motorista *>* const lista_motoristas{this->modelo->getMotoristas()};
	std::list<frota::Motorista *>::const_iterator it_mot;
	for(it_mot = lista_motoristas->begin(); it_mot != lista_motoristas->end(); ++it_mot){
		std::cout << std::endl;
        (*it_mot)->imprimeDadosPessoa();
	}
    std::cout << std::endl;
}

/**
 * Realiza a operacao especificada, reportando em caso de erro ou sucesso
 * @return void
 */
void ViewSistemaFrota::realizaOperacao(EnumTipoOperacao op){

    if(op == EnumTipoOperacao::VISUALIZAR_VEICULOS){
        std::cout << "====== Visualizar Veiculos ======\n\n";
        return this->visualizarVeiculos();
    }
    else if (op == EnumTipoOperacao::VISUALIZAR_MOTORISTAS){
        std::cout << "====== Visualizar Motoristas ======\n\n";
        return this->visualizarMotoristas();
    } 
    else if (op == EnumTipoOperacao::CADASTRAR_VEICULO){
        std::cout << "====== Cadastrar Veiculo ======\n\n";
    } 
    else if (op == EnumTipoOperacao::CADASTRAR_MOTORISTA){
        std::cout << "====== Cadastrar Motorista ======\n\n";
    } 
    else if (op == EnumTipoOperacao::SAIR){
        std::cout << "====== Até logo! ======\n";
        std::cout << "====== Desligando Sistema... ======\n\n";
    } 
    else{
        std::cout << "$$$ ERRO: Operação Invalida\n\n";
    }

}