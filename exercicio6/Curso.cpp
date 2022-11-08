#include "Curso.hpp"

Curso::Curso(std::string nomeCurso, unsigned short int anoCurso, unsigned int cargaHorariaMinima)
    :nomeCurso{nomeCurso}, anoCurso{anoCurso}, cargaHorariaMinima{cargaHorariaMinima}{
}

std::string Curso::getNomeCurso(){
	return this->nomeCurso;
}

void Curso::setNomeCurso(std::string nomeCurso){
	this->nomeCurso = nomeCurso;
}

unsigned short int Curso::getAnoCurso(){
    return this->anoCurso;
}

void Curso::setAnoCurso(unsigned short int anoCurso){
    this->anoCurso = anoCurso;
}

int Curso::getCargaHorariaMinima(){
	return this->cargaHorariaMinima;
}

void Curso::setCargaHorariaMinima(unsigned int cargaHorariaMinima){
	this->cargaHorariaMinima = cargaHorariaMinima;
}