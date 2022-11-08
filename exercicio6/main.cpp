#include<iostream>

#include<string>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"


int main(){
	
	//Alunos
	Pessoa *a1{new Pessoa{"Joao", 111111111111, 21}};
	Pessoa *a2{new Pessoa{"Maria", 22222222222, 22}};
	Pessoa *a3{new Pessoa{"Jose", 33333333333, 23}};
	Pessoa *a4{new Pessoa{"Pedro", 44444444444, 24}};
	Pessoa *a5{new Pessoa{"Ricardo", 55555555555 , 25}};
	
	//Curso
	Curso *c1{new Curso{"BCC", 2018, 2000}};

	//Professor
	Pessoa *p1 {new Pessoa{"Paulo", 9999999999, 30}};

	//Disciplina
	Disciplina d1{"Prática em Desenvolvimento de Software", p1, *c1};

	d1.adicionarAluno(a1);
	d1.adicionarAluno(a2);
	d1.adicionarAluno(a3);
	d1.adicionarAluno(a4);
	d1.adicionarAluno(a5);

	Pessoa ** vetorAlunos = d1.getVetorAlunos();
	int tamVetorAlunos = d1.getTamAlunos();

	std::cout << "### Nome do Professor: \n" << d1.getNomeProfessor() << "\n";
	
	std::cout << "### Alunos: \n";
	for (int i = 0; i < tamVetorAlunos; i++ ){
		std::cout << vetorAlunos[i]->getNome() << "\n";
	}

	Curso curso = d1.getCurso();

	std::cout << "### Curso: \n";
	std::cout << "Nome: " << curso.getNomeCurso() << "\n";
	std::cout << "Ano: " << curso.getAnoCurso() << "\n";
	std::cout << "Carga Horaria Minima: " << curso.getCargaHorariaMinima() << "\n";
	

	return 0;
}