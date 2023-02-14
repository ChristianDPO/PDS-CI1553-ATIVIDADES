#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include "Veiculo.hpp"
#include "EnumTipoCaminhao.hpp"

namespace frota {
/**
 * Classe que representa um Caminhao
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
 * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
 * @param valorVenda float Valor da venda do veiculo (em reais, entre 1000 e 800000 reais). Armazenado em um unsigned int em centavos
 * @param tipoCaminhao EnumTipoCaminhao Tipo do Caminhao
 * @param capacidade unsigned int Capacidade do Caminhao (entre 1 e 20000 kg)
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
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
            const std::string& chassi, const std::string& renavam, const float valorVenda,
            const frota::EnumTipoCaminhao tipoCaminhao, const unsigned int capacidade
        );
        
        virtual ~Caminhao() = default;

        /**
         * Retorna a capacidade do Caminhao (em kg)
         * @return unsigned int Capacidade (em kg)
         */
        unsigned int getCapacidade() const;
        /**
         * Atualiza a capacidade da Van (entre 1 e 20000 kg)
         * @param capacidade unsigned int Capacidade do Caminhao (entre 1 e 20000 kg)
         * @throws @throws std::invalid_argument Se a capacidade nao esta entre 1 e 20000 kg
         */
        void setCapacidade(const unsigned int capacidade); 

};
}

#endif