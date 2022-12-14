parametrosCompilacao=-Wall #-Wshadow
nomeAula=aula

all: $(nomeAula)

$(nomeAula): main.o Pessoa.o FilaCircular.hpp
	g++ -o $(nomeAula) main.o Pessoa.o FilaCircular.hpp $(parametrosCompilacao)

Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomeAula)
