#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
	public:
		unsigned long getCPF();
		void setCPF(unsigned long novoCPF);

		std::string getNome();
		void setNome(std::string novoNome);

		unsigned short int getIdade();
		void setIdade(unsigned short int novaIdade);

	private:
		bool validarCPF(unsigned long cpfTeste);

		std::string nome;
		unsigned long cpf;
		unsigned char idade;
};
#endif