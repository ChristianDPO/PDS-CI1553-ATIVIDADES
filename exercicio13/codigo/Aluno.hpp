#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Pessoa.hpp"

class Aluno: public Pessoa{
    public:

        Aluno(const std::string& nome, const unsigned long cpf, 
                const unsigned short int idade, const std::string& grr, const float ira);

        std::string getGRR() const;
        void setGRR(const std::string& grr);

        float getIRA() const;
        void setIRA(const float ira);

    protected:
        std::string grr; 
        float ira;


};

#endif