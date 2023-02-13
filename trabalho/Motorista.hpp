#ifndef MOTORISTA_HPP
#define MOTORISTA_HPP

#include "Pessoa.hpp"
#include "Veiculo.hpp"

#include <string>
#include <list>


namespace frota{
/**
 * Classe que representa um Motorista
 * 
 * @param nome string Nome do Motorista
 * @param cpf string CPF do Motorista (11 caracteres). Armazenado como um unsigned long
 * @param idade unsigned short int Idade do Motorista (entre 18 e 120)
 * @param cnh string Numero da Carteira Nacional de Habilitacao do Motorista (9 digitos)
 * @param cargaHoraria unsigned short int Carga horaria mensal do Motorista (entre 1 e 250 horas)
 * @param valorHora float Valor por hora trabalhada do Motorista em reais (entre 1 e 1000 reais por hora). 
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 */
class Motorista: public Pessoa{

    protected:
        
        //desconto de 50 reais por hora trabalhada nas taxas dos veiculos
        constexpr static unsigned short int valorDescontoHora{50};

        unsigned long cnh; //armazenado como um numero
        unsigned short int cargaHoraria;
        unsigned long valorHora; //armazenado em centavos
        std::list<const Veiculo*> lista_veiculos;

        /**
         * Imprime os dados especificos do determinado tipo de Pessoa
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoPessoa() const override;

    public:
        Motorista(const std::string& nome, const std::string& cpf, const unsigned short int idade,
            const std::string& cnh, unsigned short int cargaHoraria, float valorHora
        );
        virtual ~Motorista();

        bool operator==(const Motorista& outro) const;

        /**
         * Imprime os dados dos veiculos de um motorista
         * 
         * @return void
         */
        void imprimirVeiculos() const;

        /**
         * Verifica se um veiculo com a mesma placa/renavam ja esta cadastrado no sistema
         * 
         * @param veiculo Veiculo veiculo para verificar
         * @return bool True se o veiculo eh duplicado, False caso contrario
         */
        const bool verificarVeiculoDuplicado(const Veiculo& veiculo) const;

        /**
         * Adiciona um veiculo a lista de veiculos
         * @param veiculo const *Veiculo Veiculo a ser adicionado
         * @return void
         * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
         */
        const void adicionaVeiculoMotorista(const Veiculo* veiculo);

        /**
         * Calcula o valor de desconto da taxa por veiculo por hora trabalhada.
         * Esse desconto sera subtraido de cada taxa de cada veiculo do motorista
         * 
         * @return unsigned long Valor do desconto em centavos 
         */
        unsigned long calculaDescontoPorHora() const;
        
        /**
         * Calcula o salario do motorista
         * 
         * @return unsigned long Salario em centavos 
         */
        unsigned long calcularSalario() const;

        /**
         * Retorna a CNH do Motorista
         * @return string CNH do Motorista
         */
        std::string getCNH() const;
        /**
         * Retorna a CNH em formato numerico do Motorista
         * @return unsigned long CNH do Motorista
         */
        unsigned long getCNHNumerico() const;
        /**
         * Valida a CNH de um Motorista
         * @param cnh string CNH do Motorista
         * @return bool True se a CNH eh valida, False caso contrario
         */
        const bool validarCNH(const std::string& cnh) const;
        /**
         * Atualiza a CNH do Motorista
         * @param cnh string CNH do Motorista (deve ter 9 digitos numericos)
         * @throws std::invalid_argument Se a CNH eh invalida
         */
        void setCNH(const std::string& cnh);
        /**
         * Retorna a Carga horaria do Motorista
         * @return unsigned short int Carga horaria do Motorista
         */
        unsigned short int getCargaHoraria() const;
        /**
         * Atualiza a Carga horaria do Motorista
         * @param cargaHoraria string Carga horaria mensal do Motorista (entre 1 e 250)
         * @throws std::invalid_argument Se a Carga horaria eh invalida
         */
        void setCargaHoraria(const unsigned short int cargaHoraria);
        /**
         * Retorna o Valor por hora do Motorista
         * @return float Valor por hora do Motorista em reais
         */
        float getValorHora() const;
        /**
         * Atualiza o Valor por hora do Motorista
         * @param valorHora float Valor por hora do Motorista (entre 1 e 1000)
         * @throws std::invalid_argument Se o Valor por hora eh invalido
         */
        void setValorHora(const float valorHora);




};
}
#endif