#include <stdio.h>
#include <stdlib.h>
#include "dano_poder.h"

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

int main(){
    //Pokemon P1, P2;
    Treinador T1, T2;
    int rodada = 1;//define inicio e final
    FILE* arq = fopen("inicio_batalha.txt","r+t");
    if(arq == NULL){
        printf("Nao tem aquivo aqui");
        return 1;
    }   

    printf("Digite o nome do JOGADOR 1: ");
    scanf("%s",&T1.nome);
    printf("Digite o nome do JOGADOR 2: ");
    scanf("%s",&T2.nome);
    
    fscanf(arq,"%d %d",&T1.quantidade,&T2.quantidade);
    //Nome, Ataque, Defesa, Vida, Tipo
    for (int i = 0; i < T1.quantidade; i++){
        fscanf(arq,"%s %f %f %f %s", &T1.P[i].nome, &T1.P[i].ataque, &T1.P[i].defesa, &T1.P[i].vida, &T1.P[i].tipo);
    }
    for (int i = 0; i < T2.quantidade; i++){
        fscanf(arq,"%s %f %f %f %s", &T2.P[i].nome, &T2.P[i].ataque, &T2.P[i].defesa, &T2.P[i].vida, &T2.P[i].tipo);
    }
    //IMPRIMINDO JOGADORES ---------------------------------------------------------------------------
    printf("\nJOGADOR %s: \n",T1.nome);
    for (int i = 0; i < T1.quantidade; i++){
        printf("%s %.2f %.2f %.2f %s\n", T1.P[i].nome, T1.P[i].ataque, T1.P[i].defesa, T1.P[i].vida, T1.P[i].tipo);
    }
    printf("\nJOGADOR %s: \n",T2.nome);
    for (int i = 0; i < T2.quantidade; i++){
        printf("%s %.2f %.2f %.2f %s\n", T2.P[i].nome, T2.P[i].ataque, T2.P[i].defesa, T2.P[i].vida, T2.P[i].tipo);
    }
    printf("\n");

    fclose(arq);

    //BATALHA-----------------------------------------------------------------------------------------

    FILE* arquivo = fopen("fim_batalha.txt","w+t");
    int i =0, j=0;
    if(arq == NULL){
        printf("arquivo ou caminho errado");
        return 1;
    }   
    


    //tem q batalhar pelo menos uma vez -> deu errado
    //enquanto algum nao morrer, continua lutando entra si. tenho que isolar os P
    //comparar os P vida
    //quando algum morrer, vai indo ate todos morrerem
    while ((i < T1.quantidade) && (j<T2.quantidade)){
        printf("\nRODADA %d \n",rodada);
        //PRIMEIRO ATAQUE-----------------------------------------------------------------------------
        float vida_antes = T2.P[j].vida;
        efeito(T1.P[i].nome, T2.P[j].nome,
              T1.P[i].tipo, T2.P[j].tipo, 
              T1.P[i].ataque, T2.P[j].defesa, 
              T1.P[i].vida ,&T2.P[j].vida);

        //comparar se P morreu
        if (T2.P[j].vida <= 0){
            fprintf(arquivo,"%s venceu %s\n",T1.P[i].nome, T2.P[j].nome);
            printf("%s venceu %s\n",T1.P[i].nome, T2.P[j].nome);
            j++;//tem que ser antes do continue, caso ele morra
            if (j >= T2.quantidade) break; //olha se ainda tem P
        }

        //SEGUNDO ATAQUE-----------------------------------------------------------------------------
        vida_antes = T1.P[i].vida;
        efeito(T2.P[j].nome, T1.P[i].nome, 
            T2.P[j].tipo, T1.P[i].tipo, 
            T2.P[j].ataque, T1.P[i].defesa, 
            T2.P[j].vida ,&T1.P[i].vida);

        if (T1.P[i].vida <= 0){
            fprintf(arquivo,"%s venceu %s\n",T2.P[j].nome, T1.P[i].nome);
            printf("%s venceu %s\n",T2.P[j].nome, T1.P[i].nome);
            i++;
            if (i >= T1.quantidade) break;
        }
        rodada++;//muda valor

    };

    if (i< T1.quantidade){
        fprintf(arquivo,"Jogador 1 %s venceu\n",T1.nome);//soh por seguranca
        printf("--------------Jogador 1 %s venceu !----------\n",T1.nome);
    }else{
        fprintf(arquivo,"Jogador 2 %s venceu\n",T2.nome);
        printf("--------------Jogador 2 %s venceu !----------\n",T2.nome);
    }

    //SOBREVIVENTES--------------------------------------------------------------------
    fprintf(arquivo,"Pokemons sobreviventes Jogador 1 %s: \n",T1.nome);
    printf("Pokemons sobreviventes Jogador 1, %s: \n",T1.nome);
    for (int k = 0; k < T1.quantidade; k++){
        if (T1.P[k].vida > 0){
            fprintf(arquivo,"%s\t",T1.P[k].nome);
            printf("%s\t",T1.P[k].nome);
        }else{
                fprintf(arquivo,"");
                printf("");
        }
    }


    fprintf(arquivo,"\nPokemons sobreviventes Jogador 2 %s: \n",T2.nome);
    printf("\nPokemons sobreviventes Jogador 2, %s: \n",T2.nome);
    for (int l = 0; l < T2.quantidade; l++){
        if (T2.P[l].vida > 0){
            fprintf(arquivo,"%s\t",T2.P[l].nome);
            printf("%s\t",T2.P[l].nome);
        }else{
            fprintf(arquivo,"");
            printf("");
        }
    }


    //DERROTADOS--------------------------------------------------------------------
    fprintf(arquivo,"\nPokemons derrotados Jogador 1 %s: \n",T1.nome);
    printf("\nPokemons derrotados Jogador 1, %s: \n",T1.nome);
    for (int k = 0; k < T1.quantidade; k++){
        if ( T1.P[k].vida <= 0){
            fprintf(arquivo,"%s\t",T1.P[k].nome);
            printf("%s\t",T1.P[k].nome);
        }else{
            fprintf(arquivo,"");
            printf("");
        }
    }


    fprintf(arquivo,"\nPokemons derrotados Jogador 2 %s: \n",T2.nome);
    printf("\nPokemons derrotados Jogador 2, %s: \n",T2.nome);
    for (int l = 0; l < T2.quantidade; l++){
        if ( T2.P[l].vida <= 0){
            fprintf(arquivo,"%s\t",T2.P[l].nome);
            printf("%s\t",T2.P[l].nome);
        }else{
            fprintf(arquivo,"");
            printf("");
        }
    }

    
    //printf("\nDEBUG 5\n");
    
    fclose(arquivo);   
    return 0;
}