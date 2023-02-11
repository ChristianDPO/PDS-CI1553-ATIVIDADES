#ifndef CARRO_HPP
#define CARRO_HPP

#include "Veiculo.hpp"
#include "EnumTipoCarro.hpp"

namespace frota {
/**
 * Classe que representa um Carro
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo
 * @param placa string Numero da placa do veiculo (7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (17 digitos alfanumericos)
 * @param renavam unsigned long Numero do Renavam do veiculo (11 digitos numericos)
 * @param valorVenda float Valor da venda do veiculo (em reais)
 * @param tipoCarro EnumTipoCarro Tipo do carro (VIAGEM ou ENTREGA)
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
            const std::string& chassi, const unsigned long renavam, const float valorVenda,
            const frota::EnumTipoCarro tipoCarro
        );
        
        virtual ~Carro() = default;
};
}

#endif