#include <stdio.h>
#include <string.h>

//nome atacante, node defensor, tipo atacante, tipo defensor, dano atacante, defesa defensor, vidade atacante, vida defensor 
void efeito( char nome_atacante[100], char nome_defensor[100], char tipo_atacante[100], char tipo_defensor[100], float dano_atacante, float defesa_defensor, float vida_atacante, float* vida_defensor){
    //comparar minusculi
    //primeiro com vantagem
    if (
        (
            strcmp(tipo_atacante, "eletrico") == 0 && strcmp(tipo_defensor,"agua") == 0
        ) ||
        (
            strcmp(tipo_atacante, "pedra") == 0 && strcmp(tipo_defensor, "eletrico") == 0
        ) ||
        (
            strcmp(tipo_atacante, "agua") == 0 && strcmp(tipo_defensor, "fogo")==0
        ) ||
        (
            strcmp(tipo_atacante, "fogo")==0 && strcmp(tipo_defensor, "gelo")==0
        ) ||
        (
            strcmp(tipo_atacante, "gelo")==0 && strcmp(tipo_defensor, "pedra")==0
        )
    ){
        float super_efetivo = dano_atacante * 1.2f;
        //defesa_defensor = defesa_defensor - (dano_atacante*1.2);
        if (super_efetivo > defesa_defensor){
            float dano = super_efetivo - defesa_defensor;
            *vida_defensor -= dano;//testar sem mandar direto
            printf(" DEBUG 1: %s atacou %s | DANO: %.2F = (ataqueS %.2f - defesa%.2f)\n",nome_atacante,nome_defensor,dano, super_efetivo, defesa_defensor);
            printf("DEBUG 2: %s (tipo: %s) atacando %s (tipo: %s)\n", 
            nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
            printf("DEBUG 3: Ataque base: %.1f -> ", dano_atacante);
        //diferenca_defesa()
        }else{
            *vida_defensor -= 1;
            printf("DEBUG 4: %s DEFENDEU ataque do %s, -1 \n",nome_defensor,nome_atacante);
            printf("DEBUG 5: %s (tipo: %s) atacando %s (tipo: %s)\n", 
            nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
            printf("DEBUG 6: Ataque base: %.1f -> ", dano_atacante);
        }
    }else if(
        (
            strcmp(tipo_atacante, "pedra") == 0 && strcmp(tipo_defensor,"gelo") == 0
        ) ||
        (
            strcmp(tipo_atacante, "gelo") == 0 && strcmp(tipo_defensor,"fogo") == 0
        ) ||
        (
            strcmp(tipo_atacante, "fogo") == 0 && strcmp(tipo_defensor,"agua") == 0
        ) ||
        (
        strcmp(tipo_atacante, "agua") == 0 && strcmp(tipo_defensor,"eletrico") == 0
        ) ||
        (
            strcmp(tipo_atacante, "eletrico") == 0 && strcmp(tipo_defensor,"pedra") == 0
        )
        ){
      
        float nao_efetivo = dano_atacante * 0.8f;

        if (nao_efetivo > defesa_defensor){
            float dano = nao_efetivo - defesa_defensor;
            *vida_defensor -= dano;//testar sem mandar direto
            printf(" DEBUG 7: %s atacou %s | DANO: %.2F = (ataqueN %.2f - defesa%.2f)\n",nome_atacante,nome_defensor,dano, nao_efetivo, defesa_defensor);
            printf("DEBUG 8: %s (tipo: %s) atacando %s (tipo: %s)\n", 
            nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
            printf("DEBUG 9: Ataque base: %.1f -> ", dano_atacante);
        }else{
            *vida_defensor -= 1;
            printf("DEBUG 10: %s DEFENDEU ataque do %s, -1 \n",nome_defensor,nome_atacante);
            printf("DEBUG 11: %s (tipo: %s) atacando %s (tipo: %s)\n", 
            nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
            printf("DEBUG 12: Ataque base: %.1f -> ", dano_atacante);
        }

    }else{
        /*
        *vida_defensor -= 1;//testar sem mandar direto*/
        
        
        if (dano_atacante > defesa_defensor){
            float dano = dano_atacante - defesa_defensor;
            *vida_defensor -= dano;
            printf(" DEBUG 13: %s atacou %s | DANO: %.2F = (ataqueN %.2f - defesa %.2f)\n",nome_atacante,nome_defensor,dano, dano_atacante, defesa_defensor);
            printf("DEBUG 14: %s (tipo: %s) atacando %s (tipo: %s)\n", 
            nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
            printf("DEBUG 15: Ataque base: %.1f -> ", dano_atacante);
        }else{
            *vida_defensor -= 1;
            printf("DEBUG 16: %s DEFENDEU ataque do %s, -1 \n",nome_defensor,nome_atacante);
        }
        
        
    }
    //vou ter que trocar o sinal. porque o em todos, esta recebendo menos o dano 
    if (*vida_defensor < 0) {
        *vida_defensor = 0;
    }
    printf("\nvida %s, %.2f |VS| vida %s, %.2f\n", nome_defensor, *vida_defensor, nome_atacante, vida_atacante);//* em uma referencia para mostrar o valor
    printf("DEBUG 17: %s (tipo: %s) atacando %s (tipo: %s)\n", 
       nome_atacante, tipo_atacante, nome_defensor, tipo_defensor);
    printf("DEBUG 18: Ataque base: %.1f -> ", dano_atacante);
    
}