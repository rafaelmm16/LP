#include <stdarg.h>
#include <iostream>

//using namespace std;
int ou(int n, ...){//CONSTRUCAO DO COMANDO OR
    va_list valores;                //INICIALIZA A LISTA DE ARGS
    int i, r=0;
    va_start(valores, n);           //DEFINE PARA VALORES N ARGS
    for(i=0; i<n; i++){
        if(va_arg(valores, int)){   //LE UM ARG DA LISTA
            r=1;
            break;
        }
    }//FIM FOR
    va_end(valores);                //DESALOCA A LISTA
    return r;
}
int main(void){
    std::cout<<"\n"<<ou(1, 3<2);
    std::cout<<"\n"<<ou(2, 3>2<7, 10<5);    //NUMERO DE ARGUMENTOS, ARGUMENTO_01, ARGUMENTO_02, ARGUMENTO_N...
}
