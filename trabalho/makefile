parametrosCompilacao=-Wall -std=c++17
nomePrograma=frota

all: $(nomePrograma)

$(nomePrograma): main.o Veiculo.o Carro.o Caminhao.o Moto.o Van.o Pessoa.o Motorista.o ModelSistemaFrota.o VeiculoJaCadastradoException.o MotoristaJaCadastradoException.o ViewSistemaFrota.o RegexExpressoes.o 
	g++ -o $(nomePrograma) main.o Veiculo.o Carro.o Caminhao.o Moto.o Van.o Pessoa.o Motorista.o ModelSistemaFrota.o VeiculoJaCadastradoException.o MotoristaJaCadastradoException.o RegexExpressoes.o ViewSistemaFrota.o $(parametrosCompilacao)

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

Pessoa.o: Pessoa.cpp Pessoa.hpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Motorista.o: Motorista.cpp Motorista.hpp
	g++ -c Motorista.cpp $(parametrosCompilacao)

ModelSistemaFrota.o: ModelSistemaFrota.cpp ModelSistemaFrota.hpp
	g++ -c ModelSistemaFrota.cpp $(parametrosCompilacao)

ViewSistemaFrota.o: ViewSistemaFrota.cpp ViewSistemaFrota.hpp
	g++ -c ViewSistemaFrota.cpp $(parametrosCompilacao)

VeiculoJaCadastradoException.o: VeiculoJaCadastradoException.cpp VeiculoJaCadastradoException.hpp
	g++ -c VeiculoJaCadastradoException.cpp $(parametrosCompilacao)

MotoristaJaCadastradoException.o: MotoristaJaCadastradoException.cpp MotoristaJaCadastradoException.hpp
	g++ -c MotoristaJaCadastradoException.cpp $(parametrosCompilacao)

RegexExpressoes.o: RegexExpressoes.cpp RegexExpressoes.hpp
	g++ -c RegexExpressoes.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
