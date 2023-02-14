# Sistema de cadastro de motoristas e veiculos (frota)
## Descrição do Sistema

- O sistema permite o cadastro da frota de uma empresa, permitindo o cadastro de Motoristas e de Veiculos, assim como
a associação de veiculos a seus respectivos motoristas

## Regras de Negócio

### Veiculos

- O sistema permite o cadastro/remoção de veiculos, os quais todos devem ter as informações:
    - placa (string)(unico)
    - chassi (string)
    - renavam (numero)(unico)
    - valor de venda (numero)
    - ano de fabricação (numero)
    - modelo do veiculo (string)
- Não pode ser cadastrado um veiculo duplicado (com mesmo renavam ou placa)
- É possivel calcular dois tipos de informações do veiculo
    - __IPVA__: É calculado multiplicando o valor de venda do veiculo pela aliquota estadual (no PR, 3,5%).
    veiculos com mais de 20 anos (ano de fabricação menor que 2003) são isentos.
    - __TAXA__: A taxa do veiculo é uma porcentagem do valor do IPVA, que varia pelo tipo especifico do veiculo

- Há 4 tipos de veiculos:
   - __MOTO__: pode ser dos tipos
        - __SCOOTER__: taxa de 10% do IPVA
        - __PADRAO__: taxa de 12,5% do IPVA
        - __OFFROAD__: taxa de 15% do IPVA
    - __CARRO__: pode ser dos tipos
        - __VIAGEM__: taxa de 22,5% do IPVA
        - __ENTREGA__: taxa de 20% do IPVA
    - __VAN__: é um tipo de carro, então pode ser do tipo VIAGEM ou ENTREGA. Também contém o atributo:
        - capacidade (kg) (numero)
    - __CAMINHAO__: pode ser dos tipow
        - __FRETE__: taxa de 42,5% do IPVA
        - __CARRETA__: taxa de 40% do IPVA
        - também contém o atributo 'capacidade' (em kg)

## Motoristas
- O sistema permite o cadsatro/remoção de motoristas, os quais devem ter as seguintes informações
    - nome (string)
    - cpf (numerico)(unico)
    - idade (numerico)
    - cnh (numerico)(unico)
    - carga horaria mensal (numerico)
    - valor por hora (numerico)
    - uma lista de veiculos associados a ele
- Não pode ser cadastrado um motorista duplicado (com mesmo cpf ou cnh)
- É possivel calcular as seguintes informações para os motoristas:
    - __DESCONTO__: O valor do desconto por veiculo. Esse desconto é po numero de horas trabalhadas
    vezes o valor padrão de desconto por hora (10 reais). Esse desconto é retirado da taxa de cada veiculo
    - __DESCONTO TOTAL__: É a soma dos descontos de todos os veiculos do motorista
    - __TAXA TOTA__:É a soma das taxas de todos os veiculos
    - __VALOR A PAGAR__: taxa total subtraida do desconto total. Se o desconto total
    for maior que a soma das taxas, o valor a pagar é zero.
- Um motorista tem uma lista de veiculos
    - um veiculo pode ser associado/desassociado a um motorista
    - um veiculo não pode ser associado duas vezes ao mesmo motorista
    - um mesmo veiculo pode ser associado a motoristas diferentes

## Executando o sistema
- Para executar basta
    1. Entrar no diretório `src/`
    2. Executar o comando `make`
    3. Executar o comando `./frota`