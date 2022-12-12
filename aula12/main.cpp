#include <iostream>

#include "Pilha.hpp"
#include "Pessoa.hpp"

int main(){
	
	std::cout << "###Pilha inteiros\n";

	int retorno;
	Pilha<> p; //C++ menor que 17
	//Pilha p //C++ 17
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);

	while(!p.estaVazia()){
		p.pop(&retorno);
		std::cout << retorno << "\n";
	}
	
	std::cout << "###Pilha Pessoa\n";

	Pessoa retornoP;
	Pilha <Pessoa, 3> pp;

	Pessoa p1{"Maria"};
	Pessoa p2{"Jose"};
	Pessoa p3{"João"};

	pp.push(p1);
	pp.push(p2);
	pp.push(p3);

	while(!pp.estaVazia()){
		pp.pop(&retornoP);
		std::cout << retornoP.getNome() << "\n";
	}
	
	std::cout << "###Pilha Pessoa*\n";

	Pessoa* retornoPP;
	Pilha <Pessoa*, 3> ppp;

	ppp.push(&p3);
	ppp.push(&p2);
	ppp.push(&p1);

	while(!ppp.estaVazia()){
		ppp.pop(&retornoPP);
		std::cout << retornoPP->getNome() << "\n";
	}

	return 0;
}
