# PraticaDesenvSW

- Repositório para a disciplina de Prática de Desenvolvimento de Software (CI1553)
- Dividio em 'aulas' (código disponibilizado pelo professor depois das aulas) e 'exercicios' (exercicios pedidos pelo professor depois das aulas nos slides)

## Requisitos
- Compilador g++

## exercicio 1

1. Instale o g++ e as bibliotecas necessárias na sua máquina.
2. Compile o programa “olá mundo” de exemplo para testar se sua instalação está correta
3. Crie um programa em C, que deve ter o seguinte:
    - Uma struct para representar uma pessoa, com os seguintes dados: nome, cpf e idade.
    - Uma função chamada validarCPF, que recebe um número de cpf, e devolve verdadeiro ou falso, indicando se o cpf é válido ou não.
    - Pesquise na internet sobre como validar um cpf (de um jeito eﬁciente – gravar um cpf em um vetor é absurdo!).
    - No main crie um vetor com 3 elementos do tipo da struct de pessoa que você criou. Você deve solicitar os dados de 3 pessoas para o usuário, e cadastrar nesse vetor. Antes de cadastrar, você deve veriﬁcar se o cpf é válido. Se o cpf for inválido, informe ao usuário, e solicite para que ele digite outro.
    - Depois de preencher o vetor com as 3 pessoas, você deve imprimir os dados na tela.

## exercicio 2

1. Crie mais objetos do tipo pessoa no main e realize testes.
2. Pesquise em detalhes sobre #pragma once.
3. Estude o make passado em aula, e leia sobre o uso do make para compilar programas C e C++.
4. Crie uma classe que representa um retângulo. Crie objetos dessa classe no main e realize testes.

## exercicio 3

1. Modifique a classe retângulo solicitada na aula passada.
    - a. Adicione os conceitos que você aprendeu na aula de hoje.
    - b. Adicione uma função membro para:
        - i. Retornar o perímetro do retângulo.
        - ii. Retornar a área do retângulo.
2. Pesquise sobre a classe string em C++ (biblioteca string).
    - a. Dica: Para ler uma string com espaços, utilize a função global getline que está na biblioteca string, e no espaço de nomes std.
    - Obs.: para proteger de buffer overflows, talvez seja melhor usar std::istream::getline e ler para um vetor de chars, e depois criar uma string a partir do vetor.
    - Exemplo de uso std::getline(std::cin, nome)
3. Leia sobre modelos anêmicos.