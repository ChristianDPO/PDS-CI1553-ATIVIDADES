#ifndef CARRO_HPP
#define CARRO_HPP

#include "Veiculo.hpp"
#include "EnumTipoCarro.hpp"

namespace frota {
/**
 * Classe que representa um Carro
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
 * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
 * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
 * @param tipoCarro EnumTipoCarro Tipo do Carro
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 */   
class Carro: public Veiculo{
    
    protected:

        constexpr static float porcentagemCarroViagem{0.225};
        constexpr static float porcentagemCarroEntrega{0.2};

        frota::EnumTipoCarro tipoCarro;

        /**
         * Imprime os dados especificos do determinado tipo do veiculo
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoVeiculo() const override;

        /**
         * Calcula o valor da taxa ser cobrada pelo uso do veiculo, em centavos
         * 
         * @return unsigned long O valor da taxa do veiculo em centavos
         */
        virtual unsigned long calcularTaxaVeiculo() const override;

    public:
        
        Carro(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const std::string& renavam, const float valorVenda,
            const frota::EnumTipoCarro tipoCarro
        );
        
        virtual ~Carro() = default;
};
}

#endif