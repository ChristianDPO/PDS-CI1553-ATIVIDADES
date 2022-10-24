#include<iostream>

#include"Pessoa.hpp"

int main(){
	Pessoa p1;
	unsigned short int idade;
	std::string nome;

	std::cout << "Nome: ";
	std::cin >> nome;
	std::cout << "Idade: ";
	std::cin >> idade;
	
	p1.setIdade(idade);
	p1.setNome(nome);

	unsigned long cpf;

	std::cout << "CPF: ";
	std::cin >> cpf;
	
	p1.setCPF(cpf);

	std::cout << "Dados da pessoa: " << p1.getNome() << "\t" << p1.getIdade() << "\t" << p1.getCPF() << std::endl;

	return 0;
}
