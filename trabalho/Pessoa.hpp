#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

namespace frota{
/**
 * Classe que representa uma Pessoa
 * 
 * @param nome string Nome da Pessoa
 * @param cpf string CPF da pessoa (11 caracteres). Armazenado como um unsigned long
 * @param idade unsigned short int Idade da Pessoa (entre 18 e 120)
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 */
class Pessoa{

    protected:
        std::string nome;
        unsigned long cpf;
        unsigned short int idade;

        /**
         * Imprime os dados especificos do determinado tipo de Pessoa
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoPessoa() const;


    public:
        Pessoa(const std::string& nome, const std::string& cpf, const unsigned short int idade);
        virtual ~Pessoa() = default;

        /**
         * Retorna o nome da Pessoa
         * 
         * @return string Nome da Pessoa
         */
        std::string getNome() const;
        /**
         * Atualiza o nome da Pessoa
         * @return void
         */ 
        void setNome(const std::string& nome);
        /**
         * Retorna o cpf da Pessoa
         * 
         * @return string CPF da Pessoa
         */
        std::string getCPF() const;
        /**
         * Retorna o cpf numerico da Pessoa
         * 
         * @return unsgned long CPF numerico da Pessoa
         */
        unsigned long getCPFNumerico() const;
        /**
         * Valida o CPF recebido
         * 
         * @param cpf string CPF para ser validado
         * @return bool True se o CPF eh valid, False caso contrario
         */
        const bool validarCPF(const std::string cpf) const;
        /**
         * Atualiza o cpf da Pessoa
         * @param cpf string O cpf da Pessoa
         * @throws std::invalid_argument Se o cpf especificado eh invalido
         */
        void setCPF(const std::string& cpf);
        /**
         * Retorna a idade da Pessoa
         * 
         * @return unsigned short int Idade da Pessoa
         */
        unsigned short int getIdade() const; 
        /**
         * Atualiza a idade da Pessoa
         * @param cpf string O cpf da Pessoa
         * @throws std::invalid_argument Se a idade especificado nao esta entre 18 e 120 anos 
         */
        void setIdade(const unsigned short int idade);
        /**
         * Imprime os dados da Pessoa
         * 
         * @return void
         */
        void imprimeDadosPessoa() const;

};
}
#endif