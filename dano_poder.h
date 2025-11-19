#include <stdio.h>
#include <string.h>
/*
float diferenca_defesa(float defesa2, float* vida2){
        if (defesa2 <0){
            *vida2 -= defesa2;
        }else{
            *vida2 -= 1;
        }
}
*/

//nome atacante, node defensor, tipo atacante, tipo defensor, dano atacante, defesa defensor, vidade atacante, vida defensor 
void efeito( char nome_atacante[100], char nome_defensor[100], char tipo_atacante[100], char tipo_defensor[100], float dano_atacante, float defesa_defensor, float vida_atacante, float* vida_defensor){
    //comparar minusculi
    //primeiro com vantagem
    if ((tipo_atacante == "eletrico" && tipo_defensor=="agua") ||
        (tipo_atacante == "pedra" && tipo_defensor=="eletrico") ||
        (tipo_atacante == "agua" && tipo_defensor=="fogo") ||
        (tipo_atacante == "fogo" && tipo_defensor=="gelo") ||
        (tipo_atacante == "gelo" && tipo_defensor=="pedra")
    ){
        float super_efetivo = dano_atacante*1.2;
        //defesa_defensor = defesa_defensor - (dano_atacante*1.2);
        printf("DEBUG 1: %s atacou %s com dano de %.2f\n",nome_atacante,nome_defensor,super_efetivo);

        if (super_efetivo > defesa_defensor){
            float dano = super_efetivo - defesa_defensor;
            *vida_defensor -= dano;//testar sem mandar direto
        //diferenca_defesa()
        }
    }else if((tipo_atacante == "agua" && tipo_defensor=="pedra") ||
        (tipo_atacante == "fogo" && tipo_defensor=="eletrico") ||
        (tipo_atacante == "gelo" && tipo_defensor=="agua") ||
        (tipo_atacante == "pedra" && tipo_defensor=="fogo") ||
        (tipo_atacante == "eletrico" && tipo_defensor=="gelo")){
      
        float nao_efetivo = dano_atacante*0.8;
        printf("DEBUG 2: %s atacou %s com dano de %.2f\n",nome_atacante,nome_defensor,nao_efetivo);
        if (nao_efetivo > defesa_defensor){
            float dano = nao_efetivo - defesa_defensor;
            *vida_defensor -= dano;//testar sem mandar direto
        //diferenca_defesa()
        }

    }else{
        printf("%s atacou %s com dano de %.2f\n",nome_atacante,nome_defensor,1); 
        *vida_defensor -= 1;//testar sem mandar direto
    }
    printf("vida %s, %.2f |VS| vida %s, %.2f\n", nome_defensor, vida_defensor, nome_atacante, vida_atacante);
    
}