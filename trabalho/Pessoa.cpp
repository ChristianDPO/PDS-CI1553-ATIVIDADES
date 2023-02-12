#include "Pessoa.hpp"
#include "RegexExpressoes.hpp"

#include <iostream>
#include <stdexcept>

using namespace frota;


Pessoa::Pessoa(const std::string& nome, const std::string& cpf, const unsigned short int idade)
    :nome{nome}{
    this->setCPF(cpf);
    this->setIdade(idade);
}

bool Pessoa::operator==(const Pessoa& outro) const {
    return this->cpf == outro.cpf;
}

/**
 * Retorna o nome da Pessoa
 * 
 * @return string Nome da Pessoa
 */
std::string Pessoa::getNome() const { return this->nome; }

/**
 * Atualiza o nome da Pessoa
 * @return void
 */ 
void Pessoa::setNome(const std::string& nome) { 
    this->nome = nome; 
}

/**
 * Retorna o cpf da Pessoa
 * 
 * @return string CPF da Pessoa
 */
std::string Pessoa::getCPF() const { 
    
    std::string cpfString{std::to_string(this->cpf)};
    std::size_t cpfLenght = cpfString.length();

    //adiciona zeros na frente do cpf numerico para o display
    if(cpfLenght < 11)
        cpfString.insert(0, 11 - cpfLenght, '0');
    
    return cpfString;

}

/**
 * Retorna o cpf numerico da Pessoa
 * 
 * @return unsgned long CPF numerico da Pessoa
 */
unsigned long Pessoa::getCPFNumerico() const {
    return this->cpf;
}

/**
 * Valida o CPF recebido
 * 
 * @param cpf string CPF para ser validado
 * @return bool True se o CPF eh valid, False caso contrario
 */
const bool Pessoa::validarCPF(const std::string cpf) const {
    //a validacao de cpf foi simplificada para simplificar os testes
    if(!std::regex_match(cpf, frota::RegexExpressoes::regexOnzeDigitos))
        return false;
    return true;
}

/**
 * Atualiza o cpf da Pessoa
 * @param cpf string O cpf da Pessoa
 * @throws std::invalid_argument Se o cpf especificado eh invalido
 */
void Pessoa::setCPF(const std::string& cpf) { 
    
    if(!this->validarCPF(cpf))
        throw std::invalid_argument{"CPF Invalido (O CPF deve ter 11 digitos numericos)"};
    
    this->cpf = std::stol(cpf); 
}

/**
 * Retorna a idade da Pessoa
 * 
 * @return unsigned short int Idade da Pessoa
 */
unsigned short int Pessoa::getIdade() const {
    return this->idade;
}

/**
 * Atualiza a idade da Pessoa
 * @param cpf string O cpf da Pessoa
 * @throws std::invalid_argument Se a idade especificado nao esta entre 18 e 120 anos 
 */
void Pessoa::setIdade(const unsigned short int idade) {
    if (idade < 18 || idade > 120) 
        throw std::invalid_argument{"Idade Invalida (A idade para o cadastro deve estar de 18 a 120 anos)"};
    this->idade = idade;
}

/**
 * Imprime os dados especificos do determinado tipo de Pessoa
 * 
 * @return void
 */
void Pessoa::imprimeDadosPorTipoPessoa() const {
    return;
}

/**
 * Imprime os dados da Pessoa
 * 
 * @return void
 */
void Pessoa::imprimeDadosPessoa() const {
    std::cout << "###### Dados da Pessoa ######" << std::endl;
    
    this->imprimeDadosPorTipoPessoa();

    std::cout << "- Nome: " << this->nome << std::endl;
    std::cout << "- CPF: " << this->getCPF() << std::endl;
    std::cout << "- Idade: " << this->idade << " anos" << std::endl;
    
}