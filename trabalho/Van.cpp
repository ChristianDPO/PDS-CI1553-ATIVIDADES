#include "Van.hpp"

#include <iostream>

using namespace frota;

Van::Van(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const frota::EnumTipoCarro tipoCarro, const unsigned int capacidade)
    :Carro{modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro}{
    this->setCapacidade(capacidade);
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

/**
 * Retorna a capacidade da Van (em kg)
 * @return unsigned int Capacidade (em kg)
 */
unsigned int Van::getCapacidade() const { return this->capacidade; }

/**
 * Atualiza a capacidade da Van (entre 1 e 2000 kg)
 * @param capacidade unsigned int Capacidade da Van (entre 1 e 2000 kg)
 * @throws @throws std::invalid_argument Se a capacidade nao esta entre 1 e 2000 kg
 */
void Van::setCapacidade(const unsigned int capacidade){
    if(capacidade < 1 || capacidade > 2000)
        throw std::invalid_argument{
            "Capacidade invalida (Vans devem ter uma capacidade entr 1 kg e 2000 kg)"
        };
    this->capacidade = capacidade;
}