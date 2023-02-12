#ifndef VAN_HPP
#define VAN_HPP

#include "Carro.hpp"
#include "EnumTipoCarro.hpp"

using namespace frota;

namespace frota{
/**
 * Classe que representa uma Van
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
 * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
 * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
 * @param tipoCarro EnumTipoCarro Tipo do Van
 * @param capacidade unsigned int Capacidade da Van (entre 1 e 2000 kg)
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
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
            const std::string& chassi, const std::string renavam, const float valorVenda,
            const frota::EnumTipoCarro tipoCarro, unsigned int capacidade
        );
    
        virtual ~Van() = default;

        /**
         * Retorna a capacidade da Van (em kg)
         * @return unsigned int Capacidade (em kg)
         */
        unsigned int getCapacidade() const;
        /**
         * Atualiza a capacidade da Van (entre 1 e 2000 kg)
         * @param capacidade unsigned int Capacidade da Van (entre 1 e 2000 kg)
         * @throws @throws std::invalid_argument Se a capacidade nao esta entre 1 e 2000 kg
         */
        void setCapacidade(const unsigned int capacidade); 
    


};

}

#endif