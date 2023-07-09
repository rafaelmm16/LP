
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Para usar caracteres especiais de escrita
#include "excecoes.h"

using namespace std;

excecoes <int> Objeto;
excecoes <string> OutroObjeto;
excecoes <float> MeuObjeto;
excecoes <bool> ObjetoComparador;

int main(){

    string leitura;

    cout << "Digite um numero:";
    cin >> (leitura);
    //system("cls");
    //system("pause");
    OutroObjeto.isNumber(leitura);
    Objeto.isNegativeSQR(1);
    OutroObjeto.isWord(leitura);
    OutroObjeto.isDate(leitura, leitura, leitura);
}
