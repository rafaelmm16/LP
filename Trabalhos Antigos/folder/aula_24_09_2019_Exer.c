#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
/*
    Desenvolva uma rotina em C/C++/Java para realizar apostas
    aleatorias com combinacoes de 6 numeros. Os valores devem
    variar entre 1 e 60. A geracao das combinacoes aleatorias
    devem parar somente quando o ultimo numero sorteado seja
    60. Utilizar comandos iterativos com pre-teste e desvio
    incondicional.
*/
void main(){
    int numeros, i, n[6];
    for(;;){
        srand(time(NULL));
        i=0;
        while(i<6){
        numeros = rand() % 60;
        if(numeros < 1 || numeros > 60) continue;
        n[i] = numeros;
        i++;
        }//FIM WHILE
        i=0;
        for(;i<6;){
            printf("%d ", n[i]);
            i++;
        }
        printf("\n");

        if(n[5]==60)break;
    }

}//FIM DA MAIN
