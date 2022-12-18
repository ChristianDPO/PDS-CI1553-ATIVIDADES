#ifndef PESSOA_H
#define PESSOA_H

#include<string>

class Pessoa{
    public:
        Pessoa();
        Pessoa(const std::string& nome);
        Pessoa(const std::string& nome, const unsigned long cpf);
        Pessoa(const std::string& nome, const unsigned long cpf, const unsigned short int idade);

        unsigned long getCpf() const;
        void setCpf(const unsigned long cpf);

        std::string getNome() const;
        void setNome(const std::string& nome);

        unsigned short int getIdade() const;
        void setIdade(const unsigned short int idade);

        void imprimirEnderecoMemoria() const;
    protected:
        bool validarCPF(unsigned long cpfTeste) const;

        std::string nome;
        unsigned long cpf;
        unsigned char idade;
};
#endif