#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso{
    public:

        Curso(std::string nomeCurso, unsigned short int anoCurso, unsigned int cargaHorariaMinima);

		std::string getNomeCurso();
		void setNomeCurso(std::string nomeCurso);
		
        unsigned short int getAnoCurso();
        void setAnoCurso(unsigned short int anoCurso);
        
		int getCargaHorariaMinima();
		void setCargaHorariaMinima(unsigned int cargaHorariaMinima);

    private:
        std::string nomeCurso;
        unsigned short int anoCurso;
        unsigned int cargaHorariaMinima;
};
#endif