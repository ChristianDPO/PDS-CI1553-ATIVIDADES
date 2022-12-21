parametrosCompilacao=-Wall #-Wshadow
nomePrograma=prova

all: $(nomePrograma)

$(nomePrograma): main.o  Forma.o Retangulo.o Circulo.o TelaDesenho.o
	g++ -o $(nomePrograma) main.o Forma.o Retangulo.o Circulo.o TelaDesenho.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Retangulo.o: Retangulo.hpp Retangulo.cpp
	g++ -c Retangulo.cpp $(parametrosCompilacao)

Circulo.o: Circulo.hpp Circulo.cpp
	g++ -c Circulo.cpp $(parametrosCompilacao)

Forma.o: Forma.hpp Forma.cpp
	g++ -c Forma.cpp $(parametrosCompilacao)

TelaDesenho.o: TelaDesenho.hpp TelaDesenho.cpp
	g++ -c TelaDesenho.cpp $(parametrosCompilacao)


clean:
	rm -f *.o *.gch $(nomePrograma)
