#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Para usar caracteres especiais de escrita
using namespace std;
int soma(int a[], int inicio = 0, int fim = 7, int incr = 1){
    //DEFINICAO DE DEFAULT SOMENTE DA DIREITA PARA A ESQUERDA
    int soma = 0, i;
    for(i = inicio; i < fim; i+=incr)
        soma+=a[i];
        return soma;
    //FIM FOR
}//FIM SOMA

int main(){
    int pontuacao[] = {9,4,8,9,5,6,2};
    int pTotal, pQuaSab, pTerQui, pSegQuaSex;
    pTotal = soma(pontuacao);
    pQuaSab = soma(pontuacao, 3);
    pTerQui = soma(pontuacao, 2 ,5);
    pSegQuaSex = soma(pontuacao, 1 ,6 ,2);

    cout << "pTotal = " << pTotal;
    cout << "\npQuaSab = " << pQuaSab;
    cout << "\npTerQui = " << pTerQui;
    cout << "\npSegQuaSex = " << pSegQuaSex;
}
