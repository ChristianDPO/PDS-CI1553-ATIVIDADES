#ifndef PESSOA_H
#define PESSOA_H

#include<string>

class Pessoa{
	public:
		//Pessoa();
		Pessoa(std::string nome);
		Pessoa(std::string nome, unsigned short int idade);
		Pessoa(std::string nome, unsigned long cpf, unsigned short int idade);
		
		virtual ~Pessoa();

		unsigned long getCpf();
		bool setCpf(unsigned long cpf);

		std::string getNome() const;
		void setNome(const std::string& nome);

		unsigned short int getIdade();
		void setIdade(unsigned short int idade);

		void imprimirEnderecoMemoria();
	protected:
		bool validarCPF(unsigned long cpf);

		std::string nome;
		unsigned long cpf;
		unsigned char idade;
};
#endif
