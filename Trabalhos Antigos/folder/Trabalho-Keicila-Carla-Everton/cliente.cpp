#include "excecoes.h"
#include<math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*Variaveis Globais*/
int numerador=0, denominador=0,result=0,numero=0;
string sequencia;
excecoes <float> EX;
excecoes <string> EX1;
excecoes <string> EX2;
excecoes <int> EX3;
excecoes <int*>EX4;
excecoes <int>EX5;
excecoes <int>EX6;

void opcao(int op){
  switch(op){
  	case 1:
  		cout <<"Digite o numerador:\n";
        cin >>numerador;
        cout <<"Digite o denominador:\n";
        cin >>denominador;
        if((EX.isDivByZero(denominador))!=0){
                result = numerador/denominador;
                cout<<"\nResultado: "<<result<<"\n"<<endl;
        }
    break;
  	case 2:
        cout<<"\nDigite um numero\n";
        cin>>numero;

         if(EX.isNegativeSQR(numero)!=0){
            float result2 = sqrt(numero);
            cout<<"\nResultado: "<<result2<<"\n"<<endl;
        }
    break;
  	case 3:
      cin.ignore(); // limpa o buffer
  		cout<<"Digite uma sequencia:  ";
       cin>>sequencia;
  		if(EX1.isNumber(sequencia)!=0){
        cout<<"\n A sequencia Digitada : "<<sequencia<<" e digito\n "<<endl;
      }

  	break;
  	case 4:
            cin.ignore(); // limpa o buffer
            cout<<"\nDigite uma palavra\n";
            getline(cin,sequencia);
            if(EX1.isWord(sequencia)!=0){
        cout<<"\n A sequencia Digitada : "<<sequencia<<" e de caracteres\n "<<endl;
      }
  	break;
  	case 5:
  	    int dia_ex5, mes_ex5, ano_ex5;
  	    cin.ignore(); //limpa o buffer
        cout<<"\nDigita uma data:\n";
        cout<<"\nDigite o dia:\t";
        cin>>dia_ex5;
        cout<<"\nDigite o mes:\t";
        cin>>mes_ex5;
        cout<<"\nDigite o ano:\t";
        cin>>ano_ex5;
        EX5.isDate(dia_ex5, mes_ex5, ano_ex5);

  	break;
  	case 6:{
  	    int posicao;
  	    int tam=5;
  	    int vetor[tam];
        cout<<"Teste com vetor tamnho: "<<tam;
        cout<<"\nDigite a posicao que deseja acessar:\n";
        cin>>posicao;
        if(EX6.isIndexInvalid(vetor, tam, posicao)==0){
            cout<<"Posicao Valida\n";
        }
    break;}
    case 7:
    int *ptr;
       cout<<"\nDigite um numero\n";
        cin>>numerador;
                ptr=&numerador;
         if(EX3.alocation(ptr)){

        }
    break;
  }

}

int main(){
	int op;
	  while(op!=0){
	  	cout<<"=======================\nDigite\n 1)-Divisão por zero\n2)-Raiz Negativa\n3)-Tipo Numerico\n4)- Palavra\n5)-Data\n6)-Index\n7)Alocação De memoria\n0)-Sair\n";
      cin>>op;
	  	opcao(op);
      //system("clear");
	  }

}
