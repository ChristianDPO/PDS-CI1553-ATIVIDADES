# Ideia Original

Pensei em fazer um sistema de cadastro de frota/motoristas como conversei brevemente em aula. O sistema iria possibilitar o cadastro de Motoristas e de Veículos para esses motoristas. 

Um Motoristas teria seus dados (nome, cpf,cargaHoraria, valorHora, salaraio, CNH, etc) e além disso, teria uma lista de veículos associada a ele. 

Um Veículo teria suas informações (placa, valor do veículo, valor IPVA, quilômetros rodados, etc) e pode ser do tipo Moto, Carro, Van ou Caminhão (que seriam classes que herdam de Veículo). Cada veículo tem uma 'taxa' associada a ele, ou seja, cada motorista deveria pagar todas as taxas de todos os veículos usados por ele (ou veículos seriam da empresa, seria como uma 'taxa de uso'). Essa taxa seria calculada em relação aos detalhes do veículo, pensei em algo (inicial) como:

taxaPorVeiculo = porcentagem do valor do ipva

A porcentagem do IPVA iria varia pelo tipo do veículo (10% caminhão, 15% van, 20% carro e 25% moto)

Também haveria um desconto nessa taxa (por veículo) de acordo com a carga horária do motorista, quanto mais ele trabalha menos taxa ele paga: 

desconto = cargaHoraria*valorFixoDescontoPorHora

As funcionalidades que pensei do sistema seriam

1 - Cadastrar/Remover Motorista
2 - Cadastrar/Remover Veículos para um Motorista
3 - Visualizar Todos os Veículos (detalhes como ipva e taxa também seriam mostrados)
4 - Visualizar Todos os Motoristas 
5 - Vizualizar Veículos por Motorista (também mostraria a taxa total e o desconto total dessa taxa)

## Ideia atual

O sistema é um sistema de frota, que permite as seguintes funcionalidades:

1 - Listar Veiculos
2 - Listar Motoristas
3 - Cadastrar Veiculo
4 - Cadastrar Motorista
5 - Associar um Veiculo a um Motorista
6 - Vizualizar Veiculos por Motorista
7 - Remover Veiculo
8 - Remover Motorista

## Regra de Negócio

### Veiculo
- Todo Veiculo tem os seguintes atributos


### Motorista

- Tem os seguintes campos:
    - nome
    - cpf 
    - idade
    - cnh
    - valorHora
    - cargaHoraria
- Pode ser calculado o Salario do motorista
- Cada motorista tem uma lista de veiculos associada a ele
    - Dessa lista
