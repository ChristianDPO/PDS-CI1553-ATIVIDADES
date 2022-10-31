#include "Pessoa.hpp"

#include <iostream>

Pessoa::Pessoa(std::string nomePessoa)
	:nome{nomePessoa}{
}

Pessoa::Pessoa(std::string nomePessoa,
	unsigned long cpfPessoa,
	unsigned short int idadePessoa)
		:Pessoa{nomePessoa}{
	setCpf(cpfPessoa);
	setIdade(idadePessoa);
}

unsigned long Pessoa::getCpf(){
    //retorna uma cópia do cpf
    return cpf;
}

void Pessoa::setCpf(unsigned long novoCpf){
    if(validarCPF(novoCpf)){
        cpf = novoCpf;
        return;
    }
	cpf = 0;//indica que não é um cpf válido 
    return;
}

std::string Pessoa::getNome(){
    return nome;
}

void Pessoa::setNome(std::string novoNome){
    nome = novoNome;
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
