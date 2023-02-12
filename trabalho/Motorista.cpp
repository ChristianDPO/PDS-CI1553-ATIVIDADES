#include "Motorista.hpp"
#include "RegexExpressoes.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <regex>

using namespace frota;


Motorista::Motorista(const std::string& nome, const std::string& cpf, const unsigned short int idade,
        std::string cnh, unsigned short int cargaHoraria, float valorHora
    ):Pessoa{nome, cpf, idade}{
    this->setCNH(cnh);
    this->setCargaHoraria(cargaHoraria);
    this->setValorHora(valorHora);
}

bool Motorista::operator==(const Motorista& outro) const {
    return (this->cpf == outro.cpf || this->cnh == outro.cnh);
}

/**
 * Imprime os dados especificos do determinado tipo de Pessoa
 * 
 * @return void
 */
void Motorista::imprimeDadosPorTipoPessoa() const {

    std::cout << "* Qualificão: Motorista" << std::endl;
    std::cout << "* CNH: " << this->getCNH() << std::endl;
    std::cout << "* Carga Horaria: " << this->cargaHoraria << " horas" << std::endl;
    std::cout << "* Valor por Hora: R$";
    std::cout << std::fixed << std::setprecision(2) << this->getValorHora() << std::endl;
    std::cout << "* Desconto por veiculo: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calculaDescontoPorHora()/100 << std::endl;
}

/**
 * Calcula o valor de desconto da taxa por veiculo por hora trabalhada.
 * Esse desconto sera subtraido de cada taxa de cada veiculo do motorista
 * Se o desconto for maior que a taxa do veiculo, a taxa do veiculo eh anulada
 * 
 * @return unsigned long Valor do desconto em centavos 
 */
unsigned long Motorista::calculaDescontoPorHora() const {
    return Motorista::valorDescontoHora*this->cargaHoraria*100;
}

/**
 * Retorna a CNH do Motorista
 * @return string CNH do Motorista
 */
std::string Motorista::getCNH() const {
    
    std::string cnhString{std::to_string(this->cnh)};
    std::size_t cnhLenght = cnhString.length();

    //adiciona zeros na frente do cnh numerico para o display
    if(cnhLenght < 9)
        cnhString.insert(0, 9 - cnhLenght, '0');
    
    return cnhString;

}

/**
 * Retorna a CNH em formato numerico do Motorista
 * @return unsigned long CNH do Motorista
 */
unsigned long Motorista::getCNHNumerico() const { return this->cnh; }

/**
 * Valida a CNH de um Motorista
 * @param cnh string CNH do Motorista
 * @return bool True se a CNH eh valida, False caso contrario
 */
const bool Motorista::validarCNH(const std::string& cnh) const {
    if(!std::regex_match(cnh, RegexExpressoes::regexCNH))
        return false;
    return true;
}

/**
 * Atualiza a CNH do Motorista
 * @param cnh string CNH do Motorista (deve ter 9 digitos numericos)
 * @throws std::invalid_argument Se a CNH eh invalida
 */
void Motorista::setCNH(const std::string& cnh) {
    
    if(!this->validarCNH(cnh))
        throw std::invalid_argument{"CNH Invalida (A CNH deve ter 9 digitos numericos)"};
    this->cnh = std::stol(cnh);
}

/**
 * Retorna a Carga horaria do Motorista
 * @return unsigned short int Carga horaria do Motorista
 */
unsigned short int Motorista::getCargaHoraria() const { return this->cargaHoraria; }

/**
 * Atualiza a Carga horaria do Motorista
 * @param cargaHoraria string Carga horaria mensal do Motorista (entre 1 e 250)
 * @throws std::invalid_argument Se a Carga horaria eh invalida
 */
void Motorista::setCargaHoraria(const unsigned short int cargaHoraria){

    if(cargaHoraria < 1 || cargaHoraria > 250)
        throw std::invalid_argument{"Carga Horaria Invalida (A Carga Horaria deve estar entre 1 hora e 250 horas)"};
    this->cargaHoraria = cargaHoraria;
}

/**
 * Retorna o Valor por hora do Motorista
 * @return float Valor por hora do Motorista em reais
 */
float Motorista::getValorHora() const {
    return (float) this->valorHora/100;
}

/**
 * Atualiza o Valor por hora do Motorista
 * @param valorHora float Valor por hora do Motorista (entre 1 e 1000)
 * @throws std::invalid_argument Se o Valor por hora eh invalido
 */
void Motorista::setValorHora(const float valorHora){
    if(valorHora < 1 || valorHora > 1000)
        throw std::invalid_argument{
            "Valor por Hora invalido (O Valor por Hora deve estar entre 1 e 100 reais por hora)"
        };
    this->valorHora = (unsigned long) (valorHora*100);
}