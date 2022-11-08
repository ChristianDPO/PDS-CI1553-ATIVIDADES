#ifndef PESSOA_H
#define PESSOA_H

#include<string>

class Pessoa{
    public:
        Pessoa(std::string nome);
        Pessoa(std::string nome, unsigned long cpf, unsigned short int idade);

        unsigned long getCPF();
        void setCPF(unsigned long cpf);

        std::string getNome();
        void setNome(std::string nome);

        unsigned short int getIdade();
        void setIdade(unsigned short int idade);
    private:
        bool validarCPF(unsigned long cpfTeste);

        std::string nome;
        unsigned long cpf;
        unsigned char idade;
};
#endif