#include "Veiculo.hpp"
#include "RegexExpressoes.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <regex>

using namespace frota;

Veiculo::Veiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const unsigned long renavam, const float valorVenda)
    :modelo{modelo}
    {
    this->setAno(ano);
    this->setPlaca(placa);
    this->chassi = chassi;
    this->renavam = renavam;
    this->valorVenda = valorVenda*100;
}

/**
 * Calcula o IPVA do Veiculo em centavos. Veiculos fabricados a mais de vinte anos sao isentos
 *
 * @returns float O valor do IPVA em centavos. Se o Veiculo eh isento, retorna 0
 */
unsigned long Veiculo::calcularIPVA() const {
    if(this->ano <= 2003){
        return 0;
    }
    return Veiculo::aliquotaEstadual*this->valorVenda;
}

/**
 * Imprime os dados do veiculo
 * 
 * @return void
 */
void Veiculo::imprimeDadosVeiculo() const {
    std::cout << "###### Dados do Veículo ######" << std::endl;
    
    this->imprimeDadosPorTipoVeiculo();

    std::cout << "- Modelo: " << this->modelo << std::endl;
    std::cout << "- Ano: " << this->ano << std::endl;
    std::cout << "- Placa: " << this->placa << std::endl;
    std::cout << "- Número do Chassi: " << this->chassi << std::endl;
    std::cout << "- Número do Renavam: " << this->renavam << std::endl;
    std::cout << "- Valor de Venda: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->valorVenda/100 << std::endl;
    std::cout << "- Valor do IPVA: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calcularIPVA()/100 << std::endl;
    std::cout << "- Valor da Taxa de uso: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calcularTaxaVeiculo()/100 << std::endl;
}

/**
 * Retorna o modelo do veiculo
 * 
 * @return string Modelo do veiculo
 */
std::string Veiculo::getModelo() const { return this->modelo; }

/**
 * Atualiza o modelo do veiculo
 * @param modelo string Modelo do veiculo
 */
void Veiculo::setModelo(const std::string& modelo) { this->modelo = modelo; }

/**
 * Retorna o ano do veiculo
 * 
 * @return unsigned int Ano do veiculo
 */
unsigned int Veiculo::getAno() const { return this->ano; }

/**
 * Atualiza o ano do veiculo
 * @param ano unsigned int Ano do veiculo (1886 ate 2023)
 * @throws std::invalid_argument Se o ano especificado nao se econtra entre 1886 e 2023
 */
void Veiculo::setAno(const unsigned int ano) {
    if(ano < 1886 || ano > 2023)
        throw std::invalid_argument{"Ano invalido (Digite um ano de 1886 até 2023)"};
    this->ano = ano;
}

/**
 * Retorna a placa do veiculo
 * 
 * @return string placa do veiculo
 */
std::string Veiculo::getPlaca() const { return this->placa; }

/**
 * Atualiza a placa do veiculo
 * @param placa string Placa do veiculo (string alfanumerica do tipo AAA0A00)
 * @throws std::invalid_argument Se a placa nao eh uma string do tipo 'AAA0A00'
 */
void Veiculo::setPlaca(const std::string& placa){
    
    if(!std::regex_match(placa, frota::RegexExpressoes::regexPlaca)){
        throw std::invalid_argument{"Placa invalida (Digite uma placa na forma 'AAA0A00', com letras maiúsculas)"};
    }
    this->placa = placa;
}