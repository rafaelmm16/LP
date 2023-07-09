// Biblioteca de tratamento de exceções
#include <iostream>
#include <string>
#include <exception>    /* bad_alloc, bad_cast, bad_exception e etc...  */
#include <stdexcept>     /* length_error, ranger_error, overflow_error, out_of_range e etc...  */
#include <ctime>
#include <fstream>
#include <bitset>
#include <typeinfo>
using namespace std;
/*---------------
return 0 -> true
return 1 -> false
-----------------*/
/*---- Codigos --------
01 - int isDivByZero(T numero)
02 - int isNegativeSQR(T numero);
03 - int isNumber (T numero);
04 - int isWord (T palavra);
05 - int isDate (T dia, T mes, T ano);
06 -  int isIndexInvalid (T vetor[]);
07 -  T *alocation(T *ptr);
---------------------------*/

void registro(string logs,int codigo){
    time_t t = time(0);
    tm* now = localtime(&t);

    ofstream myfile;
    myfile.open ("logs.dat",ios::app);
    myfile << "CODIGO:"<<codigo<<"          "<<
               "DATA:"<<now->tm_mday<<"/"<<(now->tm_mon + 1)<<"/"<<(now->tm_year + 1900)<<"          "<<
               "HORA:"<<now->tm_hour<<":"<<(now->tm_min)<<":"<<(now->tm_sec)<<"          "<<
               "ERRO:"<<logs<<endl;
    myfile.close();
}

template <class T> class excecoes {
 public:
    class erro{ }; /*classe para referência na ocorrencia de erro. Utiliza-se construtor por ocultação*/
    void Mensagem(string msg); /*Permite passar por parâmetro qualquer mensagem e exibi-la para o usuário*/
    int isDivByZero(T numero); /*retorna true se ocorreu uma tentativa de divisão por zero*/
    int isNegativeSQR(T numero); /*retorna true se houver tentativa de raiz negativa */
    int isNumber (T numero); /*retorna true se o valor valor passado possui apenas números */
    int isWord (T palavra); /*retorna true se o valor valor passado possui apenas char */
    int isDate (T dia, T mes, T ano); /*returna true se for uma data válida */
    int isIndexInvalid (T vetor[], T tam, T posicao); /*returna true se tentar acessar uma posição de um vetor inexistente */
    T *alocation(T *ptr); /*Caso não ocorra um erro de alocação de memória devolve um ponteriro alocado */
    /*....demais métodos para tratamento de erros */
    T* teste_bad_alloc(T *ptr);
    void teste_invalid_argument();
    void teste_overflow();
    void teste_bad_cast();
    void teste_typeid();
 private:
    T item; /*Atributo privado que futuramente pode ser utilizado*/
};

template <class T> void excecoes<T>:: Mensagem(string msg) /*implementação do método mensagem */
{
      cout << msg << endl;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isDivByZero(T numero){ /*implementação da verificação de tentativa de divisao por zero */
    try {
        if (numero==0){
          throw (erro());
          return 0;
        }
        else
          return 1;
    } // final do bloco TRY
    catch (excecoes::erro){
        Mensagem("ERRO - Divisão por Zero!");
        registro("ERRO - Divisão por Zero!",01);
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isNegativeSQR(T numero){
    try{
        if(numero<0){
            throw(erro());
            return 0;
        }
        else
            return 1;
    }
    catch (excecoes::erro){
         Mensagem("ERRO - Raiz Negativa!");
         registro("ERRO - Raiz Negativa!",02);
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isNumber(T sequencia){ /*implementação da verificação de Numero*/
    try {
        int i=0, cont=0;
        int tam = sequencia.size();
        while(i<tam){
            if(isdigit(sequencia[i])){
            cont++;
            }
            i++;
        }
        if (cont!=tam){
            throw (erro());
            return 0;
        }
        else return 1;

     } // final do bloco TRY
     catch (excecoes::erro){
          Mensagem("ERRO - Nao e  Digito!");
          registro("ERRO - Nao e Digito!",03);

     }
     return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isWord(T sequencia){ /*implementação da verificação de Numero*/
 try {
        int i=0, cont=0;
        int tam = sequencia.size();
        while(i<tam){
          if(isalpha(sequencia[i])){
            cont++;
          }
          i++;
        }
        if (cont!=tam){
          throw (erro());
          return 0;
        }
        else
          return 1;
     } // final do bloco TRY
     catch (excecoes::erro){
          Mensagem("ERRO - Nao e caracater!");
          registro("ERRO - Nao e caracter!",04);
     }
     return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isIndexInvalid(T vetor[], T tam, T posicao){ /*implementação de indice*/
    try {
        if(posicao>tam-1){
            throw(erro());
            return 1;
        }
        return 0;
        }
         catch (excecoes::erro){
              Mensagem("ERRO - Acesso de posicao invalida do vetor!");
              registro("ERRO - Acesso de posicao invalida do vetor!",06);
        }
        return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> int excecoes<T>::isDate(T dia, T mes, T ano){ /*implementação da verificação de Numero*/
    try {
       if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                throw(erro());
                return 0;
            }
      }
       else
           {
               throw(erro());
                return 0;
           }
     } // final do bloco TRY
     catch (excecoes::erro){
          Mensagem("ERRO - Nao e uma data valida!");
          registro("ERRO - Nao e uma data valida!",05);
     }
     return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> T* excecoes<T>::alocation(T *ptr){
 try {
       if (*ptr = 0) {
            throw (erro());
       return NULL;
       }else {
            ptr = new (nothrow) T;
            return ptr;
        }
     } // final do bloco TRY
     catch (excecoes::erro){
          Mensagem("ERRO - ponteiro nao alocado!");
     }
     return 1;
}

////////////////////////////////////////////////////////////////////////
template <class T> T* excecoes<T>::teste_bad_alloc(T *ptr){
    try
    {
        while(true)
        {
            ptr = new int[100000];
        }
    }
    catch(bad_alloc & ex)
    {
        Mensagem("ERRO - Bad Alloc!");
        registro("ERRO - Bad Alloc!",8);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////
template <class T> void excecoes<T>::teste_invalid_argument(){
    try
        {
        // bitset constructor throws an invalid_argument if initialized
        // with a string containing characters other than 0 and 1
        std::bitset<5> mybitset (std::string("01234"));
        }
        catch (const std::invalid_argument& ia) {
        Mensagem("ERRO - Invalid Argument!");
        registro("ERRO - Invalid Argument!",9);
        }
}

////////////////////////////////////////////////////////////////////////
template <class T> void excecoes<T>::teste_overflow(){
    try
        {
            // template based
            bitset<100> bitset;
            bitset[99] = 1;
            bitset[0] = 1;
            // to_ulong(), converts a bitset object to the integer that would generate the sequence of bits

            unsigned long Test = bitset.to_ulong();
        }//FIM TRY
        catch(exception &err)
        {
            Mensagem("ERRO - Overflow!");
            registro("ERRO - Overflow",10);
        }

}

////////////////////////////////////////////////////////////////////////
template <class T> void excecoes<T>::teste_bad_cast(){
      try
        {
            class Base {virtual void member(){}};
            class Derived : Base {};
            Base b;
            Derived& rd = dynamic_cast<Derived&>(b);
        }
        catch (std::bad_cast& bc)
        {
            Mensagem("ERRO - Bad Cast!");
            registro("ERRO - Bad Cast!",11);
        }
}

////////////////////////////////////////////////////////////////////////

template <class T> void excecoes<T>::teste_typeid(){
    class Polymorphic {virtual void Member(){}};
    try
        {
            Polymorphic * pb = 0;
            std::cout << typeid(*pb).name();
        }
    catch (std::bad_typeid& bt)
        {
            Mensagem("ERRO - Bad Typied!");
            registro("ERRO - Bad Typied!",12);
        }
}

////////////////////////////////////////////////////////////////////////

/*
template <class T> T* excecoes<T>::alocation(T *ptr){

}

////////////////////////////////////////////////////////////////////////
*/
