#include "Van.hpp"

#include <iostream>

using namespace frota;

Van::Van(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const frota::EnumTipoCarro tipoCarro, const unsigned int capacidade)
    :Carro{modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro}{
    this->capacidade = capacidade;
}

/**
 * Imprime os dados especificos do determinado tipo do veiculo
 * 
 * @return void
 */
void Van::imprimeDadosPorTipoVeiculo() const {
    std::cout << "* Tipo do Veículo: Van" << std::endl;
    std::cout << "* Tipo da Van: ";
    
    if(this->tipoCarro == frota::EnumTipoCarro::VIAGEM){
        std::cout << "VIAGEM";
    }
    else{
        std::cout << "ENTREGA";
    }
    std::cout << std::endl;

    std::cout << "* Capacidade: " << this->capacidade << "kg" << std::endl;
}