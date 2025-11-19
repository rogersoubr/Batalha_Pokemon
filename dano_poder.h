#include <stdio.h>
/*
float diferenca_defesa(float defesa2, float* vida2){
        if (defesa2 <0){
            *vida2 -= defesa2;
        }else{
            *vida2 -= 1;
        }
}
*/

//nome atacante, node defensor, tipo atacante, tipo defensor, dano atacante, defesa defensor, vida defensor 
void efeito( char nome_atacante[100], char nome_defensor[100], char tipo_atacante[100], char tipo_defensor[100], float dano_atacante, float defesa_defensor, float* vida_defensor){
    //primeiro com vantagem
    if ((tipo_atacante == "eletrico" && tipo_defensor=="agua") ||
        (tipo_atacante == "pedra" && tipo_defensor=="eletrico") ||
        (tipo_atacante == "agua" && tipo_defensor=="fogo") ||
        (tipo_atacante == "fogo" && tipo_defensor=="gelo") ||
        (tipo_atacante == "gelo" && tipo_defensor=="pedra")){
        float dano = dano_atacante*1.2
        //defesa_defensor = defesa_defensor - (dano_atacante*1.2);
        printf("%s atacou %s com dano de %.2f",nome_atacante,nome_defensor,dano_atacante*1.2);
        if (defesa2 <0){
            *vida2 -= defesa2;
        }else{
            *vida2 -= 1;//acho que vou ter q mudar para +
        }
        if ((dano_atacante*1.2) > defesa_defensor){
            *vida_defensor -= defesa2;
        //diferenca_defesa()
    }else if(tipo_atacante == "gelo" && tipo_defensor=="pedra"){
        defesa2 = defesa2 - dano1*1.2;
        if (defesa2 <0){
            *vida2 -= defesa2;
        }else{
            *vida2 -= 1;//acho que vou ter q mudar para +
        }
        printf("Pokemon: %s Vida: %.2f \n", nome2, vida2);

    }else{
        defesa2 = defesa2 - dano1;
        if (defesa2 <0){
            *vida2 -= defesa2;
        }else{
            *vida2 -= 1;//acho que vou ter q mudar para +
        }
        printf("Pokemon: %s Vida: %.2f \n", nome2, vida2);
    }
    
}