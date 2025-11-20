# Sistema de Batalha Pokémon

* Para mais detalhes de documentação, acesse: [https://docs.google.com/document/d/1Lf-A4BIfoojdLq_vh_jRkWnj7FTo0pJPxmH2X6zsesQ/edit?usp=sharing](https://docs.google.com/document/d/1Lf-A4BIfoojdLq_vh_jRkWnj7FTo0pJPxmH2X6zsesQ/edit?usp=sharing)

## Estrutura de arquivos
~~~html
Batalha_Pokemon/
├── docs                    (onde ficam as documentações)
├── batalha.c               (arquivo principal para compilação do programa)
├── dano_poder.h            (arquivo com função efeito. Para cálculo e debugs dos dados Pokemons)
├── inicio_batalha.txt      (Texto de entrada de dados para a batalha)
├── fim_batalha.txt         (Texto de saída de dados para a batalha)
├── testes.txt              (Texto com testes para a batalha)
└── README.md               (Este arquivo)
~~~

## Compilação

1. Abrir um terminal e ir para o diretório
2. gcc batalha.c
3. ./a.exe 


## Estrutura de dados
~~~c
typedef struct Pokemon{
    char nome[100];
    float ataque;
    float defesa;
    float vida;
    char tipo[100];
} Pokemon;

typedef struct Treinador{
    char nome[100];
    int quantidade;
    Pokemon P[100];
} Treinador;
~~~


## Lógica

O sistema funciona através de turnos, onde cada Pokémon ataca o oponente. O dano é calculado comparando o poder de ataque do atacante com a defesa do defensor. Se o ataque passar a defesa, a diferença é subtraída da vida do oponente. Caso contrário, subtrai-se apenas 1 ponto de vida. Além disso, existe um sistema de vantagem/desvantagem baseado nos tipos dos Pokémon (Elétrico, Água, Fogo, Gelo e Pedra), onde ataques "super efetivos" causam 20% mais dano e ataques "não muito efetivos" causam 20% menos dano.

### Continuação de batalha

* Se a vida do Pokémon oponente for menor ou igual a zero, ele foi derrotado e o próximo Pokémon do jogador adversário entra na batalha.

* Caso contrário, é finalizado o turno do primeiro jogador e o Pokémon defensor se torna agora um Pokémon atacante.

* A batalha entre os jogadores continua até que todos os Pokémon de um dos jogadores sejam derrotados.

### Sistema de super e não efetividade

1. Um Pokémon do tipo “Elétrico” é forte contra Pokémon do tipo “Água” e fraco contra Pokémon do tipo “Pedra”. 

2.  Um  Pokémon  do  tipo  “Água”  é  forte  contra  Pokémon  do tipo “Fogo” e fraco contra Pokémon do tipo “Elétrico”. 

3.  Um  Pokémon  do  tipo  “Fogo”  é  forte  contra  Pokémon  do  tipo  “Gelo”  e fraco contra Pokémon do tipo “Agua”.

4.  Um  Pokémon  do  tipo  “Gelo”  é  forte contra Pokémon do tipo “Pedra” fraco contra Pokémon do tipo “Fogo”. 

5. Um Pokémon do tipo “Pedra” é forte contra Pokémon do tipo “Elétrico” e fraco contra Pokémon do tipo “Gelo”.