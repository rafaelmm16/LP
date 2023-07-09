#include <stdio.h>
#include <stdlib.h>

// === Exercicio === //
/*
Implemente em c/c++/java tres funcoes para realizar
a soma subtração e a divisao entre dois numeros
No programa principal solicita ao usuario que leia dois valores
quaisquer a e b, não simetricos. Se a > b, então calcular a subtracao entre
esses dois valores, senao calcular a divisao.
Porem independente do resultado de comparacao, realizar a soma
Para isso utilize expressao composta sem curto circuito
*/

float soma(float a, float b){
return a+b;
}

float subtracao(float a, float b){
return a-b;
}

float divisao(float a, float b){
return a/b;
}

int main(){
    float a,b;
    printf("Digite o primeiro numeoro:\t");
    scanf("%f",&a);
    printf("Digite o segundo numeoro:\t");
    scanf("%f",&b);

    a>b? printf("\nSubtracao:\t%.2f\n",subtracao(a,b)) & printf("\nSoma:\t%.2f\n",soma(a,b)) : printf("\nDivisao:\t%.2f\n",divisao(a,b)) & printf("\nSoma:\t%.2f\n",soma(a,b));

}
