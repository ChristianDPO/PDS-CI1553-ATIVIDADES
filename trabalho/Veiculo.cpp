#include "Veiculo.hpp"

#include <iostream>
#include <iomanip>

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

/**
 * Calcula o IPVA do Veiculo. Veiculos fabricados a mais de vinte anos sao isentos
 *
 * @returns float O valor do IPVA em reais. Se o Veiculo eh isento, retorna 0
 */
float Veiculo::calcularIPVA() const {
    if(this->ano <= 2003){
        return 0;
    }
    return Veiculo::aliquotaEstadual*this->valorVenda/100;
}

void Veiculo::imprimeDadosVeiculo() const {
    std::cout << "###### Dados do Veículo ######" << std::endl;
    
    this->imprimeDadosPorTipoVeiculo();

    std::cout << "- Modelo: " << this->modelo << std::endl;
    std::cout << "- Ano: " << this->ano << std::endl;
    std::cout << "- Placa: " << this->placa << std::endl;
    std::cout << "- Número do Chassi: " << this->ano << std::endl;
    std::cout << "- Número do Renavam: " << this->renavam << std::endl;
    std::cout << "- Valor de Venda: ";
    std::cout << std::fixed << std::setprecision(2) << this->valorVenda/100 << std::endl;
    std::cout << "- Valor do IPVA: ";
    std::cout << std::fixed << std::setprecision(2) << this->calcularIPVA() << std::endl;
}