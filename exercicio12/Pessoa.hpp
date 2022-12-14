#ifndef PESSOA_H
#define PESSOA_H

#include<string>

class Pessoa{
    public:
        Pessoa();
        Pessoa(std::string nome);
        Pessoa(std::string nome, unsigned long cpf, unsigned short int idade);
        ~Pessoa();

        unsigned long getCpf() const;
        void setCpf(unsigned long cpf);

        std::string getNome() const;
        void setNome(std::string nome);

        unsigned short int getIdade() const;
        void setIdade(unsigned short int idade);

        void imprimirEnderecoMemoria() const;
    private:
        bool validarCPF(unsigned long cpfTeste) const;

        std::string nome;
        unsigned long cpf;
        unsigned char idade;
};
#endif