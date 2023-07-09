#include <stdio.h>
#include <stdlib.h>
/*
int impar(int n){return n%2;}
int negativo (int n){return n<0;}
int multiplo7(int n){return !(n%7);}
int conta(int x[],int n, int(*p)(int)){
    int j,s = 0;
    for (j = 0; j<n; j++)
        if((*p)(x[j]))s++;
    return s;
}
*/
float soma (float num1, float num2){
    return (num1+num2);
}
float divisao(float num1, float num2)
    {return (num1/num2);
}
float subtracao(float num1, float num2)
    {return (num1-num2);
}
float multiplicacao(float num1, float num2){
    return (num1*num2);
}

float calculatora(float a, float b,float (*p)(float)){
    (*p)a,b

}

void menu(){

    float num1, num2;
    int opcao;
    puts("soma1\nsubtracao2\nmult3\ndivi4\n");
    scanf("%d",&opcao);
    switch(opcao){

        case 1:
            /* Soma */
            scanf("%f, %f",%num1, &num2)
            calculatora(num1,num2,soma)
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;
    }




}

main(){


    /*
int vet[10] = {1,5,8,-7,124,2,8,6,21,-9};
printf("%d\n", conta(vet, 10, impar));
printf("%d\n", conta(vet, 10, negativo));
printf("%d\n", conta(vet, 10, multiplo7));
*/

}
