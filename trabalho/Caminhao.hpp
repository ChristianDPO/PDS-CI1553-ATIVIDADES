#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Veiculo.hpp"
#include "EnumTipoCaminhao.hpp"

namespace frota {
/**
 * Classe que representa um Caminhao
 * 
 * @param modelo string Nome/modelo do Caminhao
 * @param ano unsigned int Ano de fabricacao do veiculo
 * @param placa string Numero da placa do veiculo (7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (17 digitos alfanumericos)
 * @param renavam unsigned long Numero do Renavam do veiculo (11 digitos numericos)
 * @param valorVenda float Valor da venda do veiculo (em reais)
 * @param tipoCaminhao EnumTipoCaminhao Tipo do Caminhao (VIAGEM ou ENTREGA)
 * @param capacidade unsigned int Capacidade em kg do caminhao
 */
class Caminhao: public Veiculo{
    
    protected:

        constexpr static float porcentagemCaminhaoCarreta{0.4};
        constexpr static float porcentagemCaminhaoFrete{0.425};

        frota::EnumTipoCaminhao tipoCaminhao;
        unsigned int capacidade;

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
        
        Caminhao(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const unsigned long renavam, const float valorVenda,
            const frota::EnumTipoCaminhao tipoCaminhao, const unsigned int capacidade
        );
        
        virtual ~Caminhao() = default;
};
}

#endif