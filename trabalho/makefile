parametrosCompilacao=-Wall #-Wshadow
nomePrograma=frota

all: $(nomePrograma)

$(nomePrograma): main.o Veiculo.o
	g++ -o $(nomePrograma) main.o Veiculo.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Veiculo.o: Veiculo.cpp Veiculo.hpp
	g++ -c Veiculo.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
