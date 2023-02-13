#include "ViewSistemaFrota.hpp"

#include <iostream>

using namespace frota;

ViewSistemaFrota::ViewSistemaFrota(ModelSistemaFrota* const modelo)
    :modelo{modelo}{
}

ViewSistemaFrota::~ViewSistemaFrota(){
    delete this->modelo;
}

/**
 * Tela do Menu principal
 * @return EnumTipoOperacao Operacao selcionada pelo usuario
 */
EnumTipoOperacao ViewSistemaFrota::menuPrincipal() const {
    
    unsigned short int op;

    std::cout << "====== Bem Vindo ao Sistema de Cadastro de Frotas  ======\n";
    std::cout << "====== Digite o numero de uma das operações abaixo ======";
    std::cout << "0 - Vizualizar Veiculos\n";
    std::cout << "1 - Vizualizar Motoristas\n";
    std::cout << "2 - Cadastrar Veiculos\n";
    std::cout << "3 - Cadastrar Motoristas\n";
    std::cout << "7 - Sair\n";

    std::cout << "====== Operacao: ";
    std::cin >> op;

    if(op < 1 || op > 7)
        return EnumTipoOperacao::INVALIDA;
    
    system("clear");
    
    return (EnumTipoOperacao) op;

}

/**
 * Realiza a operacao especificada, reportando em caso de erro ou sucesso
 * @return void
 */
void ViewSistemaFrota::realizaOperacao(EnumTipoOperacao op){

    if(op == EnumTipoOperacao::VISUALIZAR_VEICULOS){
        std::cout << "====== Vizualizar Veiculos ======\n\n";
    }
    else if (op == EnumTipoOperacao::VISUALIZAR_MOTORISTAS){
        std::cout << "====== Vizualizar Motoristas ======\n\n";
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