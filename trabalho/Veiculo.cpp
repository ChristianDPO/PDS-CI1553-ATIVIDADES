#include "Veiculo.hpp"
#include "RegexExpressoes.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <regex>

using namespace frota;

Veiculo::Veiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda)
    :modelo{modelo}
    {
    this->setAno(ano);
    this->setPlaca(placa);
    this->setChassi(chassi);
    this->setRenavam(renavam);
    this->setValorVenda(valorVenda);
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
    
    if(!std::regex_match(placa, frota::RegexExpressoes::regexPlaca))
        throw std::invalid_argument{"Placa invalida (A placa deve estar na forma 'AAA0A00', com letras maiúsculas)"};
    this->placa = placa;
}

/**
 * Retorna o chassi do veiculo
 * 
 * @return string chassi do veiculo
 */
std::string Veiculo::getChassi() const { return this->chassi; }

/**
 * Atualiza o chassi do veiculo
 * @param chassi string chassi do veiculo (string alfanumerica do tipo '0AAAAAAAAA0000000')
 * @throws std::invalid_argument Se o chassi nao eh uma string do tipo '0AAAAAAAAA0000000'
 */
void Veiculo::setChassi(const std::string& chassi){
    if(!std::regex_match(chassi, frota::RegexExpressoes::regexChassi))
        throw std::invalid_argument{"Chassi invalido (O chassi deve estar na forma '0AAAAAAAAA0000000', com letras maiúsculas)"};
    this->chassi = chassi;
}

/**
 * Retorna o renavam do veiculo
 * 
 * @return string Renavam do veiculo
 */
std::string Veiculo::getRenavam() const {

    std::string renavamString{std::to_string(this->renavam)};
    std::size_t renavamLenght = renavamString.length();

    //adiciona zeros na frente do renavam numerico para o display
    if(renavamLenght < 11)
        renavamString.insert(0, 11 - renavamLenght, '0');
    
    return renavamString;
}

/**
 * Atualiza o renavam do veiculo
 * @param renavam string Renavam do veiculo (string numerica de 11 digitos)
 * @throws std::invalid_argument Se o renavam especificado nao tem 11 digitos numericos
 */
void Veiculo::setRenavam(std::string renavam) {

    if(!std::regex_match(renavam, frota::RegexExpressoes::regexOnzeDigitos))
        throw std::invalid_argument{"Renavam Invalido (O Renavam deve ter 11 digitos numericos)"};
    this->renavam = std::stol(renavam);

}   

/**
 * Retorna o renavam (numerico) do veiculo
 * 
 * @return unsigned long Renavam do veiculo
 */
unsigned long Veiculo::getRenavamNumerico() const { return this->renavam; }


/**
 * Retorna o valor de venda do veiculo (em reais)
 * 
 * @return float Valor de venda do veiculo (em reais)
 */
float Veiculo::getValorVenda() const {
    return (float) this->valorVenda/100;
}

/**
 * Atualiza o renavam do veiculo (entre 1000 e 800000 reais)
 * @param valorVenda float Valor de venda do veiculo
 * @throws std::invalid_argument Se o valor de venda nao esta entre 1000 e 800000 reais
 */
void Veiculo::setValorVenda(float valorVenda) {
    if(valorVenda < 1000.0 || valorVenda > 800000.0)
        throw std::invalid_argument{
            "Valor de Venda invalido (Os veiculos devem ter um valor de venda entre 1000 e 800000 reais)"
        };
    this->valorVenda = (unsigned long) (valorVenda*100);
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
    std::cout << "- Número do Renavam: " << this->getRenavam() << std::endl;
    std::cout << "- Valor de Venda: R$";
    std::cout << std::fixed << std::setprecision(2) << this->getValorVenda() << std::endl;
    std::cout << "- Valor do IPVA: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calcularIPVA()/100 << std::endl;
    std::cout << "- Valor da Taxa de uso: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calcularTaxaVeiculo()/100 << std::endl;
}