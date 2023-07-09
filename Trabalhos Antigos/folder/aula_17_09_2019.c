#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 2, b = 9, c;

    int *p, *q;
    p = &a;
    q = &b;
    c = *p + *q;
    printf("\nResultado: %d\t%x\n", c, c);
    //%x mostra hexadecimal

    //associatividade de operadores
    a = 3;
    b = 5;
    c = -4;

    int x = a + b - c;
    //esquerda para direita
    int y = a < b < c;
    printf("x = %d\ny = %d", x, y);
    //para y a<b se sim receb 1 e b<c se nao recebe 0
    //x = **p;
    if (!!x)
        y = 3;
    printf("%d", y);
    a = b = c;
    printf("%d", a);

    // === Exercicio === //
    /*
Implemente em c/c++/java tres funcoes para realizar
a soma subtra��o e a divisao entre dois numeros
No programa principal solicita ao usuario que leia dois valores
quaisquer a e b, n�o simetricos. Se a > b, ent�o calcular a subtracao entre
esses dois valores, senao calcular a divisao.
Porem independente do resultado de comparacao, realizar a soma
Para isso utilize expressao composta sem curto circuito
*/

    printf("\nn\Exercicio\n");

} //FIM MAIN
