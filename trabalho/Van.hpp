#ifndef VAN_HPP
#define VAN_HPP

#include "Carro.hpp"
#include "EnumTipoCarro.hpp"

using namespace frota;

namespace frota{
/**
 * Classe que representa um Van
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (17 digitos alfanumericos)
 * @param renavam unsigned long Numero do Renavam do veiculo (11 digitos numericos)
 * @param valorVenda float Valor da venda do veiculo (em reais)
 * @param capacidade unsigned int Capacidade da Van em kg (de 1 ate 2000 kg)
 */   
class Van: public Carro{
    
    protected:

        unsigned int capacidade;

        /**
         * Imprime os dados especificos do determinado tipo do veiculo
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoVeiculo() const override;

    public:
        
        Van(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const unsigned long renavam, const float valorVenda,
            const frota::EnumTipoCarro tipoCarro, unsigned int capacidade
        );
        
        virtual ~Van() = default;
    


};

}

#endif