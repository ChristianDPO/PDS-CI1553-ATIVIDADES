#include<iostream>

#include<string>

#include "Pessoa.hpp"
#include "Disciplina.hpp"

int main(){
	Pessoa *p1 {new Pessoa{"Joao", 11111111111, 20}};
	Pessoa *p2 {new Pessoa{"Maria"}};

	int *ptrInt{new int}; //int com lixo
	int *ptrIntIniciado{new int{2}};//int com 2
	int *array{new int[10]}; //vetor com 10 posições

	for(int i =0; i < 10; i++){
		array[i] = i;
		std::cout << array[i] << '\n';
	}

	Disciplina d1{"Orientacao a Objetos", p1};

	std::cout << p1->getNome() << '\t' << p1->getIdade() << '\t' <<  p1->getCpf() << '\n';
	std::cout << p2->getNome() << '\n';

	std::cout << d1.getNome() << '\n';
	std::cout << d1.getProfessor()->getNome() << '\n';

	delete ptrInt;
	delete ptrIntIniciado;
	delete[] array;

	return 0;
}