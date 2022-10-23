parametrosCompilacao=-Wall #-Wshadow
nomePrograma=retangulo

all: $(nomePrograma)

$(nomePrograma): main.o Retangulo.o
	g++ -o $(nomePrograma) main.o Retangulo.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Retangulo.o: Retangulo.hpp Retangulo.cpp
	g++ -c Retangulo.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
