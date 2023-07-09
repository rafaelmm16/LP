#include <iostream>

using namespace std;

int main()
{
    int valor = 0;          
    int &ref = valor;  // ‘ref’ passa a referenciar ‘valor’
    ref = 100; 		  // ‘valor’ passa a valer 100

    cout<<"Valor: "<<valor;

    return 0;
}
