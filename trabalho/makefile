parametrosCompilacao=-Wall -std=c++17
nomePrograma=frota

all: $(nomePrograma)

$(nomePrograma): main.o Veiculo.o Carro.o Caminhao.o Moto.o Van.o RegexExpressoes.o
	g++ -o $(nomePrograma) main.o Veiculo.o Carro.o Caminhao.o Moto.o Van.o RegexExpressoes.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Veiculo.o: Veiculo.cpp Veiculo.hpp
	g++ -c Veiculo.cpp $(parametrosCompilacao)

Carro.o: Carro.cpp Carro.hpp
	g++ -c Carro.cpp $(parametrosCompilacao)

Caminhao.o: Caminhao.cpp Caminhao.hpp
	g++ -c Caminhao.cpp $(parametrosCompilacao)

Moto.o: Moto.cpp Moto.hpp
	g++ -c Moto.cpp $(parametrosCompilacao)

Van.o: Van.cpp Van.hpp
	g++ -c Van.cpp $(parametrosCompilacao)

RegexExpressoes.o: RegexExpressoes.cpp RegexExpressoes.hpp
	g++ -c RegexExpressoes.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
