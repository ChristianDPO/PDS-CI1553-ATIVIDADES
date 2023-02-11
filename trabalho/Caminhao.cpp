#include "Caminhao.hpp"

#include <iostream>

using namespace frota;

Caminhao::Caminhao(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const unsigned long renavam, const float valorVenda,
        const frota::EnumTipoCaminhao tipoCaminhao, const unsigned int capacidade)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
    this->tipoCaminhao = tipoCaminhao;
    this->capacidade = capacidade;
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