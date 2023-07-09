#include <stdio.h>

float soma(float num1, float num2){ 
    return (num1+num2);
}

float divisao(float num1, float num2){    
    return (num1/num2);
}

float calculadora (float (*p) (float, float) ) { 
    float num1,num2;   
	printf("Digite o primeiro valor\n"); 
	scanf("%f",&num1); 
	printf("Digite o segundo valor\n"); 
	scanf("%f",&num2); 
	
return ( (*p)(num1,num2) );
}

main() {        
   printf ("%f\n", calculadora(soma));  /* Deve-se usar um case*/  
   printf ("%f\n", calculadora(divisao));
    
} 

