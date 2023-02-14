#ifndef MOTO_HPP
#define MOTO_HPP

#include "Veiculo.hpp"
#include "EnumTipoMoto.hpp"

namespace frota {
/**
 * Classe que representa uma Moto
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
 * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
 * @param valorVenda float Valor da venda do veiculo (em reais, entre 1000 e 800000 reais). Armazenado em um unsigned int em centavos
 * @param tipoMoto EnumTipoMoto Tipo da Moto
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 */   
class Moto: public Veiculo{
    
    protected:

        constexpr static float porcentagemMotoOffRoad{0.15};
        constexpr static float porcentagemMotoPadrao{0.125};
        constexpr static float porcentagemMotoScooter{0.1};

        frota::EnumTipoMoto tipoMoto;

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
        
        Moto(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const std::string& renavam, const float valorVenda,
            const frota::EnumTipoMoto tipoMoto
        );
        
        virtual ~Moto() = default;
};
}

#endif