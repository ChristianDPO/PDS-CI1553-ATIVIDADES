#include "Carro.hpp"

#include <iostream>

using namespace frota;

Carro::Carro(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string& renavam, const float valorVenda,
        const frota::EnumTipoCarro tipoCarro)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
    this->tipoCarro = tipoCarro;
}

/**
 * Imprime os dados especificos do determinado tipo do veiculo
 * 
 * @return void
 */
void Carro::imprimeDadosPorTipoVeiculo() const {
    std::cout << "* Tipo do Veículo: Carro" << std::endl;
    std::cout << "* Tipo do Carro: ";
    
    if(this->tipoCarro == frota::EnumTipoCarro::VIAGEM){
        std::cout << "VIAGEM";
    }
    else{
        std::cout << "ENTREGA";
    }
    std::cout << std::endl;
}

/**
 * Calcula o valor da taxa ser cobrada pelo uso do veiculo, em centavos
 * 
 * @return unsigned long O valor da taxa do veiculo em centavos
 */
unsigned long Carro::calcularTaxaVeiculo() const {
    
    if(this->tipoCarro == frota::EnumTipoCarro::VIAGEM){
        return frota::Carro::porcentagemCarroViagem*this->calcularIPVA();
    }
    
    return frota::Carro::porcentagemCarroEntrega*this->calcularIPVA();

}