#include "Carro.hpp"

using namespace frota;

Carro::Carro(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const unsigned long renavam, const float valorVenda)
    :Veiculo{modelo, ano, placa, chassi, renavam, valorVenda}{
}