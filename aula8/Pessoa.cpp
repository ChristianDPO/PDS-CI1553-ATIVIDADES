#include "Pessoa.hpp"

#include <iostream>

Pessoa::Pessoa(){}

Pessoa::Pessoa(std::string nome)
	:nome{nome}{
}

Pessoa::Pessoa(std::string nome,
	unsigned long cpf,
	unsigned short int idade)
		:Pessoa{nome}{
	setCpf(cpf);
	setIdade(idade);
}

unsigned long Pessoa::getCpf(){
    //retorna uma cópia do cpf
    return this->cpf;
}

void Pessoa::setCpf(unsigned long cpf){
    if(validarCPF(cpf)){
        this->cpf = cpf;
        return;
    }
	this->cpf = 0;//indica que não é um cpf válido 
    return;
}

std::string Pessoa::getNome(){
    return this->nome;
}

void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

unsigned short int Pessoa::getIdade(){
    return (unsigned short int)idade;
}

void Pessoa::setIdade(unsigned short int novaIdade){
	if(novaIdade < 120)
    	idade = (unsigned char)novaIdade;
	else
		idade = 0; //indicar erro
}

void Pessoa::imprimirEnderecoMemoria(){
    std::cout << this << std::endl;
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
