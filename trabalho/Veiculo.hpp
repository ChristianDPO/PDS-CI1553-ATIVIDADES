#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <regex>

namespace frota {
/**
 * Classe que representa um veiculo generico
 * 
 * @param modelo string Nome/modelo do carro
 * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
 * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
 * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
 * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
 * @param valorVenda float Valor da venda do veiculo (em reais, entre 1000 e 800000 reais). Armazenado em um unsigned int em centavos
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 */   
class Veiculo{  
    protected:
        //taxa estadual padrao (PR) para calculo do IPVA
        constexpr static float aliquotaEstadual{0.035};

        std::string placa;
        std::string chassi;
        unsigned long renavam;//guarda renavam em um unsigned long
        unsigned long valorVenda; //guarda valor da venda num unsigned long em centavaos
        unsigned int ano;
        std::string modelo;
        
        Veiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const std::string& renavam, const float valorVenda
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
        
        bool operator==(const Veiculo& outro) const;

        /**
         * Calcula o IPVA do Veiculo em centavos. Veiculos fabricados a mais de vinte anos sao isentos
         *
         * @return float O valor do IPVA em centavos. Se o Veiculo eh isento, retorna 0
         */
        unsigned long calcularIPVA() const;
        /**
         * Retorna o modelo do veiculo
         * 
         * @return string Modelo do veiculo
         */
        std::string getModelo() const;
        /**
         * Atualiza o modelo do veiculo
         * @param modelo string Modelo do veiculo
         */
        void setModelo(const std::string& modelo);
        /**
         * Retorna o ano do veiculo
         * 
         * @return unsigned int Ano do veiculo
         */
        unsigned int getAno() const;
        /**
         * Atualiza o ano do veiculo
         * @param ano unsigned int Ano do veiculo (1886 ate 2023)
         * @throws std::invalid_argument Se o ano especificado nao se econtra entre 1886 e 2023
         */
        void setAno(const unsigned int ano);
        /**
         * Retorna a placa do veiculo
         * 
         * @return string placa do veiculo
         */
        std::string getPlaca() const;
        /**
         * Atualiza a placa do veiculo
         * @param placa string Placa do veiculo (string alfanumerica do tipo AAA0A00)
         * @throws std::invalid_argument Se a placa nao eh uma string do tipo 'AAA0A00'
         */
        void setPlaca(const std::string& placa);
        /**
         * Retorna o chassi do veiculo
         * 
         * @return string chassi do veiculo
         */
        std::string getChassi() const;
        /**
         * Atualiza o chassi do veiculo
         * @param chassi string chassi do veiculo (string alfanumerica do tipo '0AAAAAAAAA0000000')
         * @throws std::invalid_argument Se o chassi nao eh uma string do tipo '0AAAAAAAAA0000000'
         */
        void setChassi(const std::string& chassi);
        /**
         * Retorna o renavam do veiculo
         * 
         * @return string Renavam do veiculo
         */
        std::string getRenavam() const;
        /**
         * Atualiza o renavam do veiculo
         * @param renavam string Renavam do veiculo (string numerica de 11 digitos)
         * @throws std::invalid_argument Se o renavam especificado nao tem 11 digitos
         */
        void setRenavam(std::string renavam);   
        /**
         * Retorna o renavam (numerico) do veiculo
         * 
         * @return unsigned long Renavam do veiculo
         */
        unsigned long getRenavamNumerico() const;
        /**
         * Retorna o valor de venda do veiculo (em reais)
         * 
         * @return float Valor de venda do veiculo (em reais)
         */
        float getValorVenda() const;
        /**
         * Atualiza o renavam do veiculo (entre 1000 e 800000 reais)
         * @param valorVenda float Valor de venda do veiculo
         * @throws std::invalid_argument Se o valor de venda nao esta entre 1000 e 800000 reais
         */
        void setValorVenda(float valorVenda);   
        /**
         * Imprime os dados do veiculo
         * 
         * @return void
         */
        void imprimeDadosVeiculo() const;

};
}


#endif
