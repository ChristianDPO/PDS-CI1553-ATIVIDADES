#include <iostream>

#include "FilaCircular.hpp"
#include "Pessoa.hpp"

int main(){
	
	int retorno;
	FilaCircular<int, 3> q;

	q.queue(1);
	q.queue(2);
	q.dequeue(&retorno);
	q.queue(3);
	q.queue(4);

	std::cout << "\n###Imprimindo fila de elementos (inteiros)\n";
	while(!q.estaVazia()){
		q.dequeue(&retorno);
		std::cout << retorno << "\n";
	}
	
	// std::cout << "###FilaCircular Pessoa\n";

	Pessoa retornoP;
	FilaCircular <Pessoa> qp;

	Pessoa p1{"Maria"};
	Pessoa p2{"Jose"};
	Pessoa p3{"João"};
	Pessoa p4{"Emilia"};

	qp.queue(p1);
	qp.queue(p2);
	qp.queue(p3);
	qp.queue(p4);
	qp.dequeue(&retornoP);

	std::cout << "\n###Imprimindo fila de elementos (Pessoas)\n";
	while(!qp.estaVazia()){
		qp.dequeue(&retornoP);
		std::cout << retornoP.getNome() << "\n";
	}
	
	return 0;
}
