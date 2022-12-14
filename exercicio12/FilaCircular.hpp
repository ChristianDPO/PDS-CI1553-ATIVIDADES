#ifndef PILHA_HPP
#define PILHA_HPP

#include<cstdlib>
#include <iostream>

template <typename T = int, std::size_t MAX_FILA = 10>
class FilaCircular{
	public:

		FilaCircular():inicio{0}, fim{0}, n{0}{
		}

		~FilaCircular(){
		}

		bool queue(const T valor){
			
			if(this->estaCheia())
				return false;

			this->fila[this->fim] = valor;
			this->fim++;
			this->n++;

			if((size_t)this->fim == MAX_FILA)
				this->fim = 0;

			return true;
		}

		bool dequeue(T* const retorno){

			if(this->estaVazia())
				return false;

			*retorno = this->fila[inicio];
			this->inicio++;
			this->n--;

			if((size_t)this->inicio == MAX_FILA)
				this->inicio = 0;

			return true;
		
		}

		bool estaVazia() const{
			if(n == 0)
				return true;
			return false;
		}

		bool estaCheia() const{
			if((size_t)n == MAX_FILA)
				return true;
			return false;
		}

	private:
		T fila[MAX_FILA];
		int inicio; //index do inicio da fila
		int fim; //index do fim da fila
		int n; //num de elementos da fila
};

#endif
