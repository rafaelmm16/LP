#include <stdio.h>
#include <stdlib.h>
void main(){
int y,x;

x=5;
y=++x; //INCREMENTA ANTES DE PASSAR A LINHA
y=x++; //INCREMENTA DEPOIS DE PASSAR A LINHA
printf("%d\n",y);
printf("%d",x);

printf("\n\n=== OUTRO EXERCICIO ===\n\n");

x=5;
y=9;
int max = x < y ? x:y;
printf("max recebeu: %d", max);

}
