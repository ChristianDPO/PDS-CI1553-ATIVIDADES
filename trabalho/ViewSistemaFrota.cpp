#include "ViewSistemaFrota.hpp"

#include "VeiculoJaCadastradoException.hpp"
#include "MotoristaJaCadastradoException.hpp"

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
 * Tela de cadastrar veiculo
 */
void ViewSistemaFrota::cadastroVeiculo(){

    std::cout << "====== Digite as informações do Veiculo ======\n"; 
    
}
/**
 * Tela de cadastrar motorista
 */
void ViewSistemaFrota::cadastroMotorista(){

    std::string nome;
    std::string cpf;
    unsigned short int idade;
    std::string cnh;
    unsigned short int cargaHoraria;
    float valorHora;

    std::cout << "====== Digite as informações do Motorista ======\n"; 
    
    std::cout << "- Nome: ";
    std::getline(std::cin >> std::ws, nome);

    std::cout << "- CPF (11 digitos numericos, sem potuação): ";
    std::cin >> cpf;

    std::cout << "- Idade (18 a 120 anos): ";
    std::cin >> idade;

    std::cout << "- CNH (9 digitos numericos, sem potuação): ";
    std::cin >> cnh;

    std::cout << "- Carga Horaria Mensal (entre 1 e 250 horas): ";
    std::cin >> cargaHoraria;

    std::cout << "- Valor por Hora (entre 1 e 1000 reais por hora): ";
    std::cin >> valorHora;

    try{
        this->modelo->cadastrarMotorista(nome, cpf, idade, cnh, cargaHoraria, valorHora);
    } 
    catch (std::invalid_argument &iv) {
        std::cout << "$$$ ERRO: Um dado recebido foi invalido: " << iv.what() << "\n";
        return;
    } 
    catch (MotoristaJaCadastradoException &motEx) {
        std::cout << "$$$ ERRO: Conflito ao cadastrar Motorista: " << motEx.what() << "\n";
        std::cout << "$$ O CPF: " << motEx.cpf << " ou A CNH: " << motEx.cnh << " ja pertencem a um veiculo no sistema\n";
        return;
    } 
    catch (std::exception &ex) {
        std::cout << "$$$ ERRO: Algo deu errado: " << ex.what() << "\n";
        return;
    }

    std::cout << "====== Motorista cadastrado com sucesso! ======\n";
    
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
        this->cadastroMotorista();
    } 
    else if (op == EnumTipoOperacao::SAIR){
        std::cout << "====== Até logo! ======\n";
        std::cout << "====== Desligando Sistema... ======\n\n";
    } 
    else{
        std::cout << "$$$ ERRO: Operação Invalida\n\n";
    }

}