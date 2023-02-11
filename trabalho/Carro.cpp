#include "Carro.hpp"

#include <iostream>

using namespace frota;

Carro::Carro(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const unsigned long renavam, const float valorVenda)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
}


void Carro::imprimeDadosPorTipoVeiculo() const {
    std::cout << "Tipo do Veículo: Carro" << std::endl;
}