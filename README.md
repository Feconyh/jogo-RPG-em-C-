# jogo-RPG-em-C++-

Criei um jogo pequeno, no estilo RPG de mesa.
Aqui vc vai ter um player e um zumbi, um codigo com estrutura em struct e funções com ponteiros.
A premisa é que vc pode tentar atacar ou esquivar, e vai fazer a simulação de rolagem de dados usando a biblioteca random como gerador de numero aleatório.

Tambem criei uma aba para configurações, vc pode alterar os status tanto do Player quanto do Zumbi.

Os status presente são, Vida, Dt, Dano Minimo e Dano Maximo.
Vida é o quanto de dano vc pode receber, se chegar a 0 vc morre.
Dt é a dificuldade de teste, aqui eu usei como se fosse a Defesa/esquiva, ela é a margem que decide de um ataque acertou ou não.
Dano minimo é o valor minimo que o dado pode rolar.
Dano Maximo é o valor maximo que o dado pode rolar.

Sobre Dt.
Por padrao vc rola 1d20. mas pode ser modificado nas configurações.

Exemplar para dano.
caso quero rolar 1d12(1 dado de 12 lados).
vc tera o dano minimo em 1 e o dano maximo em 12.

por outro lado caso vc queira rolar 2d6(2 dados de 6 lados).
vc tera o dano minimo em 2 e o dano maximo em 12. ja que vc sempre ira somar os dados e quando jogado 2 dados n existe uma soma menor do que 1.
