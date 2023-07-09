#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calculaProcessamento()
{
    int TAM = 400000000; /* Quantidade de repetições do laço  */

    double Tempo;
    int *vetor;
    vetor = (int *)calloc(TAM, sizeof(int));
    if (vetor == NULL)
        printf("** Erro: Memoria Insuficiente **");

    clock_t TempoClock[2];
    int i;

    register int count; /* Testar sendo register e não register   */

    TempoClock[0] = clock();

    for (count = 0; count < TAM; count++) /* testar sendo count register e não register   */
        vetor[count] = count;
    //O código a ter seu tempo de execução medido deve ficar antes deste ponto

    TempoClock[1] = clock();

    Tempo = (TempoClock[1] - TempoClock[0]) * 1000 / CLOCKS_PER_SEC;

    printf("\n Tempo gasto foi de: %g ms.", Tempo);
}
///////////////////////////////////////////////////////Quantidadevoid calculaProcessamento()

int main()
{
    calculaProcessamento();

    return 0;
}
