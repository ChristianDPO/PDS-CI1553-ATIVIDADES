#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>

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
class Veiculo{  
    protected:
        //taxa estadual padrao (PR) para calculo do IPVA
        constexpr static float aliquotaEstadual{0.035};
        
        std::string placa;
        std::string chassi;
        unsigned long renavam;
        unsigned long valorVenda; //guarda o valor da venda em centavos
        unsigned int ano;
        std::string modelo;
        
        Veiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const unsigned long renavam, const float valorVenda
        );

        /**
         * Imprime os dados especificos do determinado tipo do veiculo
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoVeiculo() const = 0;
        
        /**
         * Calcula o valor da taxa ser cobrada pelo uso do veiculo, em centavos 
         * 
         * @return unsigned long O valor da taxa do veiculo em centavos
         */
        virtual unsigned long calcularTaxaVeiculo() const = 0;

    public:
        
        virtual ~Veiculo() = default; 
        
        /**
         * Calcula o IPVA do Veiculo em centavos. Veiculos fabricados a mais de vinte anos sao isentos
         *
         * @return float O valor do IPVA em centavos. Se o Veiculo eh isento, retorna 0
         */
        unsigned long calcularIPVA() const;
        /**
         * Imprime os dados do veiculo
         * 
         * @return void
         */
        void imprimeDadosVeiculo() const;
        
};
}


#endif
