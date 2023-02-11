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

    public:
        virtual ~Veiculo() = default;
        
        /**
         * Calcula o IPVA do Veiculo. Veiculos fabricados a mais de vinte anos sao isentos
         *
         * @returns float O valor do IPVA em reais. Se o Veiculo eh isento, retorna 0
         */
        float calcularIPVA() const;
        
};
}


#endif
