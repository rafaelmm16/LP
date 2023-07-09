#include <stdio.h>
#include <stdlib.h>

enum Quartenario {FALSO, VERDADEIRO, INTERMEDIARIO, MAXIMO};
typedef enum Quartenario tipo_enum;

void main(){
    float notas[3], media;

    printf("Digite as notas de 1 a 3:\t");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    media = ((notas[0]+notas[1]+notas[2])/3);

    tipo_enum status;
    if(media >= 7 && media < 10){
        status = VERDADEIRO;
    }
    else if(media < 7 && media < 5){
        status = FALSO;
    }
    else if(media >= 5 && media <7){
        status = INTERMEDIARIO;
    }
    else if (media == 10){
        status = MAXIMO;
    }
    printf("Nota 01:\t%f\nNota 02:\t%f\nNota 03:\t%f\nMedia:\t%f\n", notas[0], notas[1], notas[2], media);
    switch(status){
        case 0:{
            puts("ALUNO REPROVADO!");
            break;
        }
        case 1:{
            puts("ALUNO APROVADO!");
            break;
        }
        case 2:{
            puts("ALUNO APROVADO (INTERMEDIARIO)");
            break;
        }
        case 3:{
            puts("ALUNO APROVADO (MAXIMO)");
            break;
        }
        default: break;
    }

}

