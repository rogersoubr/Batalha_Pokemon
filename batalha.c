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
    Pokemon P[50]
} Treinador;

int main(){
    //Pokemon P1, P2;
    Treinador T1, T2;
    int result, rodada = 1;//define inicio e final
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
    //imprimindo
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

    //----------------------------------------------------------------------------------------

    FILE* arquivo = fopen("inicio_batalha.txt","w+t");
    int i =0, j=0;


    //tem q batalhar pelo menos uma vez
    //enquanto algum nao morrer, continua lutando entra si. tenho que isolar os P
    //comparar os P
    //quando algum morrer, vai indo ate todos morrerem
    do{
        printf("\nRODADA %d \n",rodada);
        efeito(T1.P[i].nome,T2.P[j].nome, T1.P[i].tipo, T2.P[j].tipo, T1.P[i].ataque, T2.P[j].defesa, T1.P[i].vida ,&T2.P[j].vida);

        if (T2.P[j].vida <= 0){
            printf("%s matou %s\n",T1.P[i].nome, T2.P[j].nome);
            j++;
            continue;//vou ter que usar para comeca outra rodada
        }

        efeito(T1.P[j].nome,T2.P[i].nome, T1.P[j].tipo, T2.P[i].tipo, T1.P[j].ataque, T2.P[i].defesa, T1.P[j].vida ,&T2.P[i].vida);

        if (T2.P[i].vida <= 0){
            printf("%s matou %s\n",T1.P[i].nome, T2.P[j].nome);
            i++;
            //continue;//vou ter que usar para comeca outra rodada
        }
        rodada++;

    } while ((i < T1.quantidade) && (j<T2.quantidade));

    if (i< T1.quantidade){
        //fprintf();
        printf("--------------Jogador1 %s venceu !----------\n",T1.nome);
    }else{
        printf("--------------Jogador1 %s venceu !----------\n",T2.nome);
    }
    
        
        

         
    /*
    for (i ; i < T1.quantidade; i++){
        for (j ; j < T2.quantidade; j++){
            printf("\nJogada %d:\n", i+1);
            efeito(T1.P[i].nome,T2.P[j].nome, T1.P[i].tipo, T2.P[j].tipo, T1.P[i].ataque, T2.P[j].defesa, &T2.P[j].vida);
            printf("\nDEBUG 2\n");

            if (T1.P[j].vida <= 0){
                printf("%s matou %s",T1.P[i].nome, T2.P[j].nome);
                printf("\nDEBUG 3\n");
            }
                
        }
        if (T1.P[i].vida <= 0){
            printf("%s matou %s",T2.P[j].nome, T1.P[i].nome);
            printf("\nDEBUG 4\n");   
            
    }
    */
    printf("\nDEBUG 5\n");
    
    //fclose(arquivo);   
    return 0;
}