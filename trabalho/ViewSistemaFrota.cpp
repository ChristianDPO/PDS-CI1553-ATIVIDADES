#include "ViewSistemaFrota.hpp"

#include "VeiculoJaCadastradoException.hpp"
#include "MotoristaJaCadastradoException.hpp"
#include "VeiculoNaoEncontradoException.hpp"
#include "MotoristaNaoEncontradoException.hpp"

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
    std::cout << "4 - Selecionar Motorista (Visualisar e Associar Veiculos)\n";
    std::cout << "7 - Sair\n";

    std::cout << "====== Operação: ";
    std::cin >> op;

    if(op < 0 || op > 7)
        return EnumTipoOperacao::INVALIDA;
    
    system("clear");
    
    return static_cast<EnumTipoOperacao>(op);

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

    std::string modelo;
    unsigned int ano;
    std::string placa;
    std::string chassi;
    std::string renavam;
    float valorVenda;
    
    unsigned short int entrada;

    std::cout << "====== Digite as informações do Veiculo ======\n"; 

    std::cout << "- Modelo: ";
    std::getline(std::cin >> std::ws,modelo);

    std::cout << "- Ano (1886 ate 2023): ";
    std::cin >> ano;

    std::cout << "- Placa (7 caracteres alfanumericos  do tipo 'AAA0A00', sem pontuação): ";
    std::cin >> placa;

    std::cout << "- Chassi (17 caracteres alfanumerica do tipo '0AAAAAAAAA0000000', sem pontuação): ";
    std::cin >> chassi;

    std::cout << "- Renavam (11 digitos numericos, sem potuação): ";
    std::cin >> renavam;

    std::cout << "- Valor de Venda (em reais, entre 1000 e 800000 reais): ";
    std::cin >> valorVenda;

    std::cout << "====== Selecione o número do tipo do Veiculo ======\n";
    std::cout << "0 - MOTO\n";
    std::cout << "1 - CARRO\n";
    std::cout << "2 - VAN\n";
    std::cout << "3 - CAMINHÃO\n";
    std::cout << "====== Tipo (número de 0 a 3): ";
    
    std::cin >> entrada;
    if(entrada < 0 || entrada > 3){
        std::cout << "$$$ERRO: Tipo de Veiculo Invalido\n";
        return;
    }

    EnumTipoVeiculo tipoVeiculo{static_cast<EnumTipoVeiculo>(entrada)};
    
    EnumTipoMoto tipoMoto;
    EnumTipoCarro tipoCarro;
    EnumTipoCaminhao tipoCaminhao;
    unsigned int capacidade;

    try{

        if(tipoVeiculo == EnumTipoVeiculo::MOTO){
            
            std::cout << "====== Selecione o número do tipo da Moto ======\n";
            std::cout << "0 - SCOOTER\n";
            std::cout << "1 - PADRAO\n";
            std::cout << "2 - OFFROAD\n";
            std::cout << "====== Tipo (número de 0 a 2): ";

            std::cin >> entrada;
            if(entrada < 0 || entrada > 2){
                std::cout << "$$$ERRO: Tipo de Moto Invalido\n";
                return;
            }

            tipoMoto = static_cast<EnumTipoMoto>(entrada);
            this->modelo->cadastrarVeiculo(modelo, ano, placa, chassi, renavam, valorVenda, tipoMoto);

        }
        else if(tipoVeiculo == EnumTipoVeiculo::CARRO){
            
            std::cout << "====== Selecione o número do tipo do Carro ======\n";
            std::cout << "0 - VIAGEM\n";
            std::cout << "1 - ENTREGA\n";
            std::cout << "====== Tipo (número de 0 a 1): ";

            std::cin >> entrada;
            if(entrada < 0 || entrada > 1){
                std::cout << "$$$ERRO: Tipo de Carro Invalido\n";
                return;
            }   

            tipoCarro = static_cast<EnumTipoCarro>(entrada);
            this->modelo->cadastrarVeiculo(modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro);

        } else if(tipoVeiculo == EnumTipoVeiculo::VAN){
            
            std::cout << "====== Selecione o número do tipo da Van ======\n";
            std::cout << "0 - VIAGEM\n";
            std::cout << "1 - ENTREGA\n";
            std::cout << "====== Tipo (número de 0 a 1): ";

            std::cin >> entrada;
            if(entrada < 0 || entrada > 1){
                std::cout << "$$$ERRO: Tipo de Van Invalido\n";
                return;
            }   

            tipoCarro = static_cast<EnumTipoCarro>(entrada);
            
            std::cout << "- Capacidade da Van (entre 1 e 2000 kg): ";
            std::cin >> capacidade;
            
            this->modelo->cadastrarVeiculo(modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro, capacidade);
        } else if(tipoVeiculo == EnumTipoVeiculo::CAMINHAO){
            
            std::cout << "====== Selecione o número do tipo do Caminhão ======\n";
            std::cout << "0 - FRETE\n";
            std::cout << "1 - CARRETA\n";
            std::cout << "====== Tipo (número de 0 a 1): ";

            std::cin >> entrada;
            if(entrada < 0 || entrada > 1){
                std::cout << "$$$ERRO: Tipo de Caminhão Invalido\n";
                return;
            }   

            tipoCaminhao = static_cast<EnumTipoCaminhao>(entrada);
            
            std::cout << "- Capacidade do Caminhao (entre 1 e 20000 kg): ";
            std::cin >> capacidade;
            
            this->modelo->cadastrarVeiculo(modelo, ano, placa, chassi, renavam, valorVenda, tipoCaminhao, capacidade);
        }

    } 
    catch (std::invalid_argument &iv) {
        std::cout << "$$$ ERRO: Um dado recebido foi invalido: " << iv.what() << "\n";
        return;
    } 
    catch (VeiculoJaCadastradoException &veiEx) {
        std::cout << "$$$ ERRO: Conflito ao cadastrar Veiculo: " << veiEx.what() << "\n";
        std::cout << "$$ O Renavam: " << veiEx.renavam << " ou A Placa: " << veiEx.placa << " ja pertencem a um veiculo no sistema\n";
        return;
    } 
    catch (std::exception &ex) {
        std::cout << "$$$ ERRO: Algo deu errado: " << ex.what() << "\n";
        return;
    }

    std::cout << "====== Veiculo cadastrado com sucesso! ======\n\n";


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

    std::cout << "====== Motorista cadastrado com sucesso! ======\n\n";
    
}

/**
 * Tela para selecionar um motorista, mostrando os seus detalhes e permetindo adicionar/remover seus veiculos
 */
void ViewSistemaFrota::selecionaMotorista(){
    
    std::string cpf;
    std::string placa;

    std::cout << "====== Buscar Motorista por CPF ======\n"; 
    std::cout << "- CPF (11 digitos numericos, sem potuação): ";
    std::cin >> cpf;

    unsigned short int entrada;

    std::cout << "====== Digite o número da operação a ser realizada ======\n"; 
    std::cout << "1 - Visualizar Motorista\n";
    std::cout << "3 - Associar Veiculo ao Motorista\n";
    std::cout << "6 - Remover Veiculo do Motorista\n";
    std::cout << "7 - Voltar\n";
    std::cout << "====== Operação: ";
    std::cin >> entrada;

    if(entrada != 1 && entrada != 3 && entrada != 6 && entrada != 7){
        std::cout << "$$$ERRO: Tipo Operação Inválida\n";
        return;
    }   

    EnumTipoOperacao op{static_cast<EnumTipoOperacao>(entrada)};

    if(op == EnumTipoOperacao::SAIR)
        return;

    if(op == EnumTipoOperacao::VISUALIZAR_MOTORISTAS){
        
        const Motorista* motorista{this->modelo->getMotorista(cpf)};

        if(motorista == nullptr){
            std::cout << "$$$ ERRO: Motorista com CPF: " << cpf <<" não foi econtrado\n";
            return;
        }

        std::cout << "====== Detalhes do Motorista ======\n\n"; 
        motorista->imprimeDadosPessoa();
        motorista->imprimirVeiculos();
        std::cout << std::endl;

    } 
    else{

        std::cout << "====== Digite a placa do Veiculo ======\n"; 
        std::cout << "- Placa (7 caracteres alfanumericos  do tipo 'AAA0A00', sem pontuação): ";
        std::cin >> placa;

        if(op == EnumTipoOperacao::CADASTRAR_MOTORISTA){

            try{
                this->modelo->associarVeiculoMotorista(placa, cpf);
            } catch( VeiculoNaoEncontradoException& vneEx){
                std::cout << "$$$ ERRO: Falha ao associar Veiculo: " << vneEx.what() << "\n";
                std::cout << "$$ A Placa: " << vneEx.placa << " não pertence a um veiculo no sistema\n";
                return;
            } catch( MotoristaNaoEncontradoException& mneEx){
                std::cout << "$$$ ERRO: Falha ao associar Veiculo: " << mneEx.what() << "\n";
                std::cout << "$$ O CPF: " << mneEx.cpf << " não pertence a um motorista no sistema\n";
                return;
            }
            catch (VeiculoJaCadastradoException &veiEx) {
                std::cout << "$$$ ERRO: Conflito ao cadastrar Veiculo: " << veiEx.what() << "\n";
                std::cout << "$$ Um veiculo com o Renavam: " << veiEx.renavam << " ou com a Placa: " << veiEx.placa << " ja está assosiado a esse motorista\n";
                return;
            } 

            std::cout << "====== Veiculo associado com sucesso! ======\n"; 
        } else if(op == EnumTipoOperacao::REMOVER_MOTORISTA){

            try{
                this->modelo->desassociarVeiculoMotorista(placa, cpf);
            } catch( VeiculoNaoEncontradoException& vneEx){
                std::cout << "$$$ ERRO: Falha ao desassociar Veiculo: " << vneEx.what() << "\n";
                std::cout << "$$ A Placa: " << vneEx.placa << " não pertence a um veiculo no sistema\n";
                return;
            } catch( MotoristaNaoEncontradoException& mneEx){
                std::cout << "$$$ ERRO: Falha ao desassociar Veiculo: " << mneEx.what() << "\n";
                std::cout << "$$ O CPF: " << mneEx.cpf << " não pertence a um motorista no sistema\n";
                return;
            }

            std::cout << "====== Veiculo desassociado com sucesso! ======\n"; 
        }
    }
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
        this->cadastroVeiculo();
    } 
    else if (op == EnumTipoOperacao::CADASTRAR_MOTORISTA){
        std::cout << "====== Cadastrar Motorista ======\n\n";
        this->cadastroMotorista();
    } 
    else if (op == EnumTipoOperacao::SELECIONAR_MOTORISTA){
        std::cout << "====== Selecionar Motorista ======\n\n";
        this->selecionaMotorista();
    } 
    else if (op == EnumTipoOperacao::SAIR){
        std::cout << "====== Até logo! ======\n";
        std::cout << "====== Desligando Sistema... ======\n\n";
    } 
    else{
        std::cout << "$$$ ERRO: Operação Invalida\n\n";
    }

}