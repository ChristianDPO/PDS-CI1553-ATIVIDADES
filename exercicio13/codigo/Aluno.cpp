#include "Aluno.hpp"
#include "Pessoa.hpp"

Aluno::Aluno(const std::string& nome, const unsigned long cpf, 
            const unsigned short int idade, const std::string& grr, const float ira)
            :Pessoa{nome, cpf, idade}, grr{grr}, ira{ira}{
}


std::string Aluno::getGRR() const{
    return this->grr;
}

void Aluno::setGRR(const std::string& grr){
    this->grr = grr;
};

float Aluno::getIRA() const{
    return this->ira;
}

void Aluno::setIRA(const float ira){
    this->ira = ira;
};