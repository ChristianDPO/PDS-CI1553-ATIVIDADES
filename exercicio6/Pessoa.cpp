#include "Pessoa.hpp"

#include <iostream>

Pessoa::Pessoa(std::string nome)
	:nome{nome}{
}

Pessoa::Pessoa(std::string nome,
	unsigned long cpf,
	unsigned short int idade)
		:Pessoa{nome}{
	setCPF(cpf);
	setIdade(idade);
}

unsigned long Pessoa::getCPF(){
    //retorna uma cópia do cpf
    return cpf;
}

void Pessoa::setCPF(unsigned long cpf){
    if(validarCPF(cpf)){
        this->cpf = cpf;
        return;
    }
	this->cpf = 0;//indica que não é um cpf válido 
    return;
}

std::string Pessoa::getNome(){
    return nome;
}

void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

unsigned short int Pessoa::getIdade(){
    return (unsigned short int)idade;
}

void Pessoa::setIdade(unsigned short int idade){
	if(idade < 120)
    	this->idade = (unsigned char)idade;
	else
		this->idade = 0; //indicar erro
}

bool Pessoa::validarCPF(unsigned long cpfTeste){
	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	int penultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	
	somatorioValidaUltimo = penultimo*2;
	for(int i=2; i <= 11; i++){
		modulo = cpfTeste%10;
		cpfTeste = cpfTeste/10;
		somatorioValidaPenultimo += modulo*i;
		somatorioValidaUltimo += modulo*(i+1);
	}
	modulo = somatorioValidaPenultimo%11;
	if(modulo < 2){
		if(!penultimo)
			return false;//cpf invalido
	}else{
		if(penultimo != 11 - modulo)
			return false;//cpf invalido
	}
	modulo = somatorioValidaUltimo%11;
	if(modulo < 2){
		if(!ultimo)
			return false;//cpf invalido
	}else{
		if(ultimo != 11-modulo)
			return false;//cpf invalido
	}
	return true;//cpf valido
}
