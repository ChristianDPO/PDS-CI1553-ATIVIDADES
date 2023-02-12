#include "Caminhao.hpp"

#include <iostream>

using namespace frota;

Caminhao::Caminhao(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string& renavam, const float valorVenda,
        const frota::EnumTipoCaminhao tipoCaminhao, const unsigned int capacidade)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
    this->tipoCaminhao = tipoCaminhao;
    this->setCapacidade(capacidade);
}

/**
 * Imprime os dados especificos do determinado tipo do veiculo
 * 
 * @return void
 */
void Caminhao::imprimeDadosPorTipoVeiculo() const {
    std::cout << "* Tipo do Veículo: Caminhao" << std::endl;
    std::cout << "* Tipo do Caminhao: ";
    
    if(this->tipoCaminhao == frota::EnumTipoCaminhao::FRETE){
        std::cout << "FRETE";
    }
    else{
        std::cout << "CARRETA";
    }
    std::cout << std::endl;

    std::cout << "* Capacidade: " << this->capacidade << "kg" << std::endl;
}

/**
 * Calcula o valor da taxa ser cobrada pelo uso do veiculo, em centavos
 * 
 * @return unsigned long O valor da taxa do veiculo em centavos
 */
unsigned long Caminhao::calcularTaxaVeiculo() const {
    
    if(this->tipoCaminhao == frota::EnumTipoCaminhao::FRETE){
        return frota::Caminhao::porcentagemCaminhaoFrete*this->calcularIPVA();
    }
    
    return frota::Caminhao::porcentagemCaminhaoCarreta*this->calcularIPVA();

}

/**
 * Retorna a capacidade do Caminhao (em kg)
 * @return unsigned int Capacidade (em kg)
 */
unsigned int Caminhao::getCapacidade() const { return this->capacidade; }

/**
 * Atualiza a capacidade do Caminhao (entre 1 e 20000 kg)
 * @param capacidade unsigned int Capacidade da Van (entre 1 e 20000 kg)
 * @throws @throws std::invalid_argument Se a capacidade nao esta entre 1 e 20000 kg
 */
void Caminhao::setCapacidade(const unsigned int capacidade){
    if(capacidade < 1 || capacidade > 2000)
        throw std::invalid_argument{
            "Capacidade invalida (Caminhões devem ter uma capacidade entr 1 kg e 20000 kg)"
        };
    this->capacidade = capacidade;
}