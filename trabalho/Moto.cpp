#include "Moto.hpp"

#include <iostream>

using namespace frota;

Moto::Moto(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const frota::EnumTipoMoto tipoMoto)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
    this->tipoMoto = tipoMoto;
}

/**
 * Imprime os dados especificos do determinado tipo do veiculo
 * 
 * @return void
 */
void Moto::imprimeDadosPorTipoVeiculo() const {
    std::cout << "* Tipo do Veículo: Moto" << std::endl;
    std::cout << "* Tipo da Moto: ";
    
    if(this->tipoMoto == frota::EnumTipoMoto::SCOOTER){
        std::cout << "SCOOTER";
    }
    else if(this->tipoMoto == frota::EnumTipoMoto::PADRAO){
        std::cout << "PADRÃO";
    }
    else{
        std::cout << "OFFROAD";
    }
    std::cout << std::endl;
}

/**
 * Calcula o valor da taxa ser cobrada pelo uso do veiculo, em centavos
 * 
 * @return unsigned long O valor da taxa do veiculo em centavos
 */
unsigned long Moto::calcularTaxaVeiculo() const {
    
    if(this->tipoMoto == frota::EnumTipoMoto::SCOOTER){
        return frota::Moto::porcentagemMotoOffRoad*this->calcularIPVA();
    }
    else if(this->tipoMoto == frota::EnumTipoMoto::PADRAO){
        return frota::Moto::porcentagemMotoPadrao*this->calcularIPVA();
    }
    
    return frota::Moto::porcentagemMotoOffRoad*this->calcularIPVA();

}