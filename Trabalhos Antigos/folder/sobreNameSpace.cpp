#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

namespace azul{         //SEMELHANTE A UM BLOCO OU STRUCT
    int soma(int x){
        x=x+1;
        return x;
    }//FIM SOMA
}//FIM AZUL

namespace branco{       //SEMELHANTE A UM BLOCO OU STRUCT
    int soma(int x){
        x+=x;
    }//FIM SOMA

    void cout(std::string nome){
        std::cout<<"\n#"<<nome<<"#";
    }

}//FIM BRANCO


int main (void){
//using namespace branco;
//Usando este comando acima, nao seria necessario chamar branco::
//Porem poderia causar conflito
//O mesmo vale para "using namespace std"
//Que nao seria necessario chamar std:: nos comandos basicos;
    int numero;

    std::cout<<"Digite um numero:\t";
    std::cin>>numero;

    branco::cout("\nA soma obtida eh:\t");
    std::cout<<azul::soma(numero);

    branco::cout("\nA outra soma obtida eh:\t");
    std::cout<<branco::soma(numero);

}
