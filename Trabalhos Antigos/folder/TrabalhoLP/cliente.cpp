#include "excecoes.h"
#include<math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
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
    case 7:/*
    int *ptr;
       cout<<"\nDigite um numero\n";
        cin>>numerador;
                ptr=&numerador;
         if(EX3.alocation(ptr)){

        }*/
    case 8:
        //TESTE BAD ALLOC
        int *teste;
        EX6.teste_bad_alloc(teste);
        break;
    case 9:
        //  O construtor do bitset lança um invalid_argument se inicializado
        //  com uma string contendo caracteres diferentes de 0 e 1
        EX6.teste_invalid_argument();
        break;
    case 10:
        EX6.teste_overflow();
        break;
    case 11:
        EX6.teste_bad_cast();
        break;
    case 12:
        EX6.teste_typeid();
        break;
  }

}

int InitGL(GLvoid)                                                              // All Setup For OpenGL Goes Here
{
        glShadeModel(GL_SMOOTH);                                                // Habilita sombreamento suavizado
                                                                                // Mistura cores de forma suave me um polígono
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                                   // Fundo negro
        glClearDepth(1.0f);                                                     // Inicialização do Depth Buffer
        glEnable(GL_DEPTH_TEST);                                                // Habilita teste de profundidade
        glDepthFunc(GL_LEQUAL);                                                 // Define qual teste de profundidade vai ser feito
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);                      // Calculos de perspectiva legaizinhos
        return TRUE;                                                            // Fazemos de conta que sempre dá tudo certo retornando OK
}
int redesenhaMundo(GLvoid)                                       // É aqui que desenhamos TUDO
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Limpe a tela e o buffer
     glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);            // Indique que os dois lados de qualquer superfície devem ser representados.
     glLoadIdentity();                                           // Resete a corrente Modelview Matrix

     /* eh AQUI que você vai chamar todas as funcoes que
        desenham algo */

     glutSwapBuffers();                                          // Troque os buffers. Isto ainda não possui nenhum efeito.
                                                                 // Quando você começar a desenhar vai ver que no modo double-buffer,
                                                                 // você desenha no buffe rescondido e depois mostra o desenho pronto.


}//FIM REDESENHA MUNDO
/*===========================================================*/
/* Funcao que chama redraw.                                                                      */
/* Endereco passado como a Idle Function, funcao que         */
/* o laco do GLUT chama quando nao esta fazendo outra coisa. */
void
mostraMundo(void)
/*===========================================================*/
{

        redesenhaMundo();

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
