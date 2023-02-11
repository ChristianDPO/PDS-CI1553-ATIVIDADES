#include "Veiculo.hpp"

using namespace frota;


Veiculo::Veiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const unsigned long renavam, const float valorVenda)
    {
    this->modelo = modelo;
    this->ano = ano;
    this->placa = placa;
    this->chassi = chassi;
    this->renavam = renavam;
    this->valorVenda = valorVenda*100;
}


float Veiculo::calcularIPVA() const {
    if(this->ano <= 2003){
        return 0;
    }
    return Veiculo::aliquotaEstadual*this->valorVenda/100;
}