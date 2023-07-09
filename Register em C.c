#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TAM = 5;

void calculo()
{
    register int i, j;
    int **mat;
    int linha, coluna;

    printf("Informe a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("Informe a quantidade de colunas: ");
    scanf("%d", &coluna);

    mat = (int **)malloc(sizeof(int *)*linha);
    if (mat = NULL)
    {
        printf("Memoria insuficiente \n");
    }

    for (i = 0; i < linha; i++)
    {
        mat[i] = (int *)malloc(sizeof(int)*coluna);
        if (mat = NULL)
        {
            printf("Memoria insuficiente \n");
        }
    }

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("Preencha: ");
            scanf("%d", mat[i][j]);
        }
    }
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            //mat[i][j] = linha * coluna;

            printf("Calculo: %6.f", mat[i][j]);
        }
    }
}

int main(void)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        calculo();
    }

    return 0;
}
