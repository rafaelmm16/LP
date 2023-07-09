// Biblioteca de tratamento de exceções
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>
#include <stdexcept>
#include <math.h>

using namespace std;


template <class T> class excecoes {
 public:
    class erro{ }; /*classe para referência na ocorrencia de erro. Utiliza-se construtor por ocultação*/
    void Mensagem(string msg); /*Permite passar por parâmetro qualquer mensagem e exibi-la para o usuário*/
    bool isDivByZero(T numero); /*retorna true se ocorreu uma tentativa de divisao por zero*/
    bool isNegativeSQR(T numero); /*retorna true se houver tentativa de raiz negativa */
    bool isNumber (T numero); /*retorna true se o valor valor passado possui apenas números */
    bool isWord (T palavra); /*retorna true se o valor valor passado possui apenas char */
    bool isDate (T dia, T mes, T ano); /*returna true se for uma data válida */
    T *alocation(T *ptr); /*Caso não ocorra um erro de alocação de memmória devolve um ponteriro alocado */
    //....demais métodos para tratamento de erros
 private:
    T item; /*Atributo privado que futuramente pode ser utilizado*/
};

template <class T> void excecoes<T>:: Mensagem(string msg) /*implementação do método mensagem */
{
      cout << msg << endl;
}
///////////////////////////////////////////////////////////////////
template <class T> bool excecoes<T>::isDivByZero(T numero){ /*implementação da verificação de tentativa de divisao por zero */
 try {
        if (numero==0){
          throw (erro());
        return true;
        }
        else
        return false;
     } // final do bloco TRY
     catch (excecoes::erro){
          Mensagem("Erro de Divisao por Zero!");
     }
}

template <class T> bool excecoes<T>::isNegativeSQR(T numero){/*retorna true se houver tentativa de raiz negativa */
    try{
        if(numero<0){
        throw (erro());
        return true;
        }
    }
    catch (excecoes::erro){
        Mensagem("Raiz de numero negativo");
    }
}
template <class T> bool excecoes<T>::isNumber(T numero){ /*retorna true se o valor valor passado possui apenas números */
    try{
        bool valor = true;
        for(int i=0; i<numero.size(); i++){
            if(!isdigit(numero[i]) && numero[i] != '.'){
                cout << numero; //SYSOUT DE C++
                valor = false;
            }//FIM IF
            if(!valor){
                throw (erro());
                return true;
            }//FIM IF
        }//FIM FOR
    }//FIM TRY
    catch (excecoes::erro){
          Mensagem("\nNao eh um numero!\n");
     }
}
template <class T> bool excecoes<T>::isWord(T palavra){/*retorna true se o valor valor passado possui apenas char */
   try{
        bool valor = true;
        for(int i=0; i<palavra.size(); i++){
            if(isdigit(palavra[i])){
                cout << palavra; //SYSOUT DE C++
                valor = false;
            }//FIM IF
            if(!valor){
                throw (erro());
                return true;
            }//FIM IF
        }//FIM FOR
    }//FIM TRY
    catch (excecoes::erro){
          Mensagem("\nNao eh apenas char!\n");
     }
}
template <class T> bool excecoes<T>::isDate(T dia, T mes, T ano){/*returna true se for uma data válida */

   try{
        bool valor = true;
        if(!excecoes(isNumber(dia)) || !excecoes(inNumber(mes)) || !excecoes(isNumber(ano))){
            throw (erro());

                valor = false;
            //FIM IF
            if(!valor){
                throw (erro());
                return true;
            }//FIM IF
        }//FIM IF
    }//FIM TRY
   catch (excecoes::erro){
          Mensagem("\nData invalida\n");
    }

}
void gravar (int vetor[], int tamanho){
    FILE *arq;
    arq = fopen("LogErros.dat", "wb");

    if(arq!=NULL){
        fwrite(vetor, sizeof(int), tamanho, arq);
    }
    else
        printf("Arquivo nao criado <<<Error<<");
    fclose(arq);
}

int *leitura(int vetor[], int tamanho){
    FILE *arq;
    arq = fopen("LogErros.dat", "rb");
    if(arq != NULL){
        fread(vetor, sizeof(int), tamanho, arq);
        fclose(arq);
    }
    return vetor;
}
