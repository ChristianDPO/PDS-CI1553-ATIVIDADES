#include "Motorista.hpp"
#include "RegexExpressoes.hpp"

#include "VeiculoJaCadastradoException.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <regex>

using namespace frota;


Motorista::Motorista(const std::string& nome, const std::string& cpf, const unsigned short int idade,
        const std::string& cnh, const unsigned short int cargaHoraria, const float valorHora
    ):Pessoa{nome, cpf, idade}{
    this->setCNH(cnh);
    this->setCargaHoraria(cargaHoraria);
    this->setValorHora(valorHora);
}

Motorista::~Motorista(){
}

bool Motorista::operator==(const Motorista& outro) const {
    return (this->cpf == outro.cpf || this->cnh == outro.cnh);
}

/**
 * Verifica se um veiculo com a mesma placa/renavam ja esta cadastrado no sistema
 * 
 * @param veiculo Veiculo veiculo para verificar
 * @return bool True se o veiculo eh duplicado, False caso contrario
 */
const bool Motorista::verificarVeiculoDuplicado(const Veiculo& veiculo) const {
    
    std::list<const frota::Veiculo *>::const_iterator it;

	for(it = this->lista_veiculos.begin(); it != this->lista_veiculos.end(); ++it)
		if (**it == veiculo)
            return true;
	return false;

}

/**
 * Adiciona um veiculo a lista de veiculos
 * @param veiculo const *Veiculo Veiculo a ser adicionado
 * @return void
 * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
 */
void Motorista::adicionaVeiculoMotorista(const Veiculo* veiculo){

    if(this->verificarVeiculoDuplicado(*veiculo))
        throw VeiculoJaCadastradoException{veiculo->getRenavam(), veiculo->getPlaca()};
    
    this->lista_veiculos.push_back(veiculo);
}

/**
 * Remove o veiculo do Motorista
 * @param placa string Placa do veiculo a ser removido
 * @return bool True se o veiculo foi encontrado e removido, False caso contrario
 */
const bool Motorista::removeVeiculoMotorista(const std::string& placa){
    
    std::list<const frota::Veiculo *>::iterator it;
	for(it = this->lista_veiculos.begin(); it != this->lista_veiculos.end(); ++it)
		if((*it)->getPlaca() == placa){
            this->lista_veiculos.erase(it);
            return true;
        }
    return false;
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
    std::cout << "* Salario: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calcularSalario()/100 << std::endl;
    std::cout << "* Desconto por veiculo: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calculaDescontoPorHora()/100 << std::endl;
    std::cout << "* Taxa Total: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calculaTaxaTotal()/100 << std::endl;
    std::cout << "* Desconto Total: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calculaDescontoTotal()/100 << std::endl;
    std::cout << "* Total a pagar: R$";
    std::cout << std::fixed << std::setprecision(2) << (float) this->calculaValorPagar()/100 << std::endl;
    this->imprimirVeiculos();
 
}

/**
 * Imprime os dados dos veiculos de um motorista
 * 
 * @return void
 */
void Motorista::imprimirVeiculos() const{
    
    std::cout << "------- Veiculos Associados -------" << std::endl;
    std::list<const frota::Veiculo *>::const_iterator it;
	for(it = this->lista_veiculos.begin(); it != this->lista_veiculos.end(); ++it){
		(*it)->imprimeDadosVeiculo();
	}
    std::cout << "-----------------------------------" << std::endl;
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
 * Calcula desconto total.
 * O desconto total eh a soma de todos os descontos para cada veiculo
 * 
 * @return unsigned long Valor do desconto total em centavos 
 */
unsigned long Motorista::calculaDescontoTotal() const {
    return this->lista_veiculos.size()*this->calculaDescontoPorHora();
}

/**
 * Calcula a taxa total a pagar
 * A taxa total eh a soma de todas as taxas de todos os veiculos subtraido do desconto total
 * 
 * @return unsigned long Valor da taxa total em centavos 
 */
unsigned long Motorista::calculaTaxaTotal() const{
    
    unsigned long taxa{0};

    std::list<const frota::Veiculo *>::const_iterator it;
	for(it = this->lista_veiculos.begin(); it != this->lista_veiculos.end(); ++it){
		taxa += (*it)->calcularTaxaVeiculo();
	}

    return taxa;
}

/**
 * Calcula o valor a pagar (taxa total - desconto total)
 * Se o desconto total for maior que a taxa total, o valor a pagar e zero
 * 
 * @return unsigned long Valor a pagar do motorista em centavos
 */
unsigned long Motorista::calculaValorPagar() const{
    
    long taxaTotal{static_cast<long>(this->calculaTaxaTotal())};
    long descontTotal{static_cast<long>(this->calculaDescontoTotal())};

    long resultado{taxaTotal - descontTotal};

    if(resultado <= 0)
        return 0;
    
    return static_cast<unsigned long>(resultado);

}

/**
 * Calcula o salario do motorista
 * 
 * @return unsigned long Salario em centavos 
 */
unsigned long Motorista::calcularSalario() const {
    return this->valorHora*this->cargaHoraria;
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