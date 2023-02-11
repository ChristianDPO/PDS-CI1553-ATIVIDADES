#ifndef CARRO_HPP
#define CARRO_HPP

#include "Veiculo.hpp"

namespace frota {
/**
 * Classe que representa um veiculo generico
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo
 * @param placa string Numero da placa do veiculo (7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (17 digitos alfanumericos)
 * @param renavam unsigned long Numero do Renavam do veiculo (11 digitos numericos)
 * @param valorVenda float Valor da venda do veiculo (em reais)
 */ 
class Carro: public Veiculo{
    
    public:
        Carro(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const unsigned long renavam, const float valorVenda
        );
        virtual ~Carro() = default;
};
}

#endif