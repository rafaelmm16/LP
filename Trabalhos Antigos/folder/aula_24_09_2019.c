#include <stdio.h>
#include <stdlib.h>

void main(){
    //FOR SEMELHANTE A WHILE
    int s=0;
    for(;;){
        s=s+1;
        if(s==10)break;
    }
    printf("%d\n",s);

    //TESTE DE ESCAPTE GOTO
    s=0;
    for(;;){
        s=s+1;
        if(s==5)goto saida;
        if(s==10)break;
    }
    //BLOCO DE COMANDO PARA GOTO
    saida:
        printf("eita, pulou pelo goto!!!");

    //CONTINUE
    printf("\n\nUSANDO O CONTINUE\n\n");
    int n, i = 0;
    s = 0;
    while(i<5){
        printf("n: ");
        scanf("%d", &n);
        if(n<0)continue; //CASO SEJA MENOR QUE ZERO ELE VOLTA PRO INICIO DO LAÇO
        s+=n;            //E NAO CONTABILIZA AS LINHAS A BAIXO DELE
        i++;
    }//FIM WHILE
    printf("%d", s);
}//MAIN

