#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define POST(L) ((L)->prox)
#define ANT(L) ((L)->ant)
#define IP(L) ((L)->ip)
#define USUARIO(L) ((L)->usuario)
#define METODO(L) ((L)->metodo)
#define PATH(L) ((L)->path)
#define HTTP(L) ((L)->http)
#define AGENTE(L) ((L)->agente)
#define DATA(L) ((L)->data)
#define STATUS(L) ((L)->status)
#define BYTES(L) ((L)->bytes)

/*		ORDEM DOS CÓDIGOS
ListaLogApache *cria(ListaLogApache *p_L)
ListaLogApache *Carrega_arquivo(FILE *arquivo)
void imprime(ListaLogApache *l)
void *buscaImprime(ListaLogApache *p_L)
ListaLogApache *busca(ListaLogApache *l)
ListaLogApache *exclui(ListaLogApache *p_L)
JaTem *Aloca_JaTem(JaTem *p_L, char ip[])
noUsuario *alocaUsuario(noUsuario *p_L, char usuario[])
int Repetido(JaTem *lista ,char ip_novo[])
int Repetido2(noUsuario *lista ,char usuario_novo[])
void repetidos(ListaLogApache *p_L)
ListaLogApache *desaloca(ListaLogApache *l)
void trafego(ListaLogApache *p_L)
*/

typedef struct lista{
	char ip[50], usuario[255], metodo[255], path[255], http[255], agente[255], data[100];
	char hora[4];
	int status;
	long bytes;
	struct lista *prox;
	struct lista *ant;
}ListaLogApache;

//----------------------------------------------------------

ListaLogApache *cria(ListaLogApache *p_L){   //cria e insere no fim
	ListaLogApache *novo = (ListaLogApache*)malloc(sizeof(ListaLogApache));
	POST(novo)= p_L;
	ANT(novo)= NULL;

	// -------- 2) --------
	// -------- Antiga --------
	/*if(p_L != NULL)
		ANT(p_L) = novo;*/
	// -------- Nova --------
	(p_L != NULL) ? (ANT(p_L) = novo) : (ANT(p_L));

	return novo;
}

//----------------------------------------------------------

ListaLogApache *Carrega_arquivo(FILE *arquivo){
	ListaLogApache *L1 = NULL;

	while(!feof(arquivo)){  //feof(arquivo) final arquivo
		L1 = cria(L1);
		fscanf(arquivo, "%s %*c %s [%s %*d] \"%s %s %[^\"]\" %d %ld %*s \"%[^\"]\"", IP(L1), USUARIO(L1), DATA(L1), METODO(L1), PATH(L1), HTTP(L1), &STATUS(L1), &BYTES(L1), AGENTE(L1));
		// -------- 3) --------
		L1->hora[0]=L1->data[12];
		L1->hora[1]=L1->data[13];
	//	printf("\n- %s -\n",L1->hora);
	}
	return L1;
}

//----------------------------------------------------------

void imprime(ListaLogApache *l){
	// -------- 1), c) --------
	ListaLogApache *aux = l;
	while(aux != NULL){
		printf("%s %s %s %s %s %s %d %ld %s\n", IP(aux), USUARIO(aux), DATA(aux), METODO(aux), PATH(aux), HTTP(aux), STATUS(aux), BYTES(aux), AGENTE(aux));
		aux = POST(aux);
	}
}

//----------------------------------------------------------

void *buscaImprime(ListaLogApache *p_L){   //AGORA A BUSCA ESTA DE BOA, COM OPÇÃO.
	char ip[50], usuario[255],data[100], metodo[255], path[255], http[255], agente[255];
	int opcao,ativo=1;
    ListaLogApache *aux = p_L;
    do{
            printf("\n____________________________\nComo deseja realizar a busca:\n1 - IP\n2 - USUARIO\n3 - DATA\n4 - METODO\n5 - PATH \n6 - HTPP\n7 - AGENTE \n8 - VOLTAR\n____________________________\n");
            printf("Escolha a opcao:");
            scanf("%d", &opcao);
			fflush(stdin);

			// -------- 7) Multiplos Caminhos --------

    		switch(opcao){
			case 1:
			    printf("Insira um numero de IP: \n");
                scanf("%s", ip);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(IP(aux), ip)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;
			case 2:
                printf("Insira um Usuario: \n");
                scanf("%s", usuario);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(USUARIO(aux), usuario)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 3:
                printf("Insira a data e horario: Modelo (dia/mes/ano:hora:minutos:segundos)\n");
                scanf("%s", data);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(DATA(aux), data)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 4:
                printf("Insira um Metodo: \n");
                scanf("%s", metodo);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(METODO(aux), metodo)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 5:
                printf("Insira um path: \n");
                scanf("%s", path);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(PATH(aux), path)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 6:
                printf("Insira um HTPP: \n");
                scanf("%s", http);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(HTTP(aux), http)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

            case 7:
                printf("Insira o agente: \n");
            //	__fpurge(stdin);
                scanf("%s", agente);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(AGENTE(aux), agente)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

            case 8:
            	ativo=0;
                break;

			default:
				printf("Opcao Invalida!!\n");
		}
    }while(ativo);
	printf("Nao encontrado ou operacao abortada \n");

}

//--------------------- BUSCA COM RETORNO -------------------------------------

ListaLogApache *busca(ListaLogApache *l){   //AGORA A BUSCA ESTA DE BOA, COM OPÇÃO.
	char ip[50], usuario[255],data[100], metodo[255], path[255], http[255], agente[255];
	int opcao,ativo=1;
    ListaLogApache *aux = l;
    do{
            printf("\n____________________________\nComo deseja realizar a busca:\n1 - IP\n2 - USUARIO\n3 - DATA\n4 - METODO\n5 - PATH \n6 - HTPP\n7 - AGENTE \n8 - VOLTAR\n____________________________\n");
            printf("Escolha a opcao:");
            scanf("%d", &opcao);
			fflush(stdin);

    		switch(opcao){
			case 1:
			    printf("Insira um numero de IP: \n");
                scanf("%s", ip);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(IP(aux), ip)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;
			case 2:
                printf("Insira um Usuario: \n");
                scanf("%s", usuario);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(USUARIO(aux), usuario)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 3:
                printf("Insira a data e horario: Modelo (dia/mes/ano:hora:minutos:segundos)\n");
                scanf("%s", data);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(DATA(aux), data)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 4:
                printf("Insira um Metodo: \n");
                scanf("%s", metodo);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(METODO(aux), metodo)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 5:
                printf("Insira um path: \n");
                scanf("%s", path);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(PATH(aux), path)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

			case 6:
                printf("Insira um HTPP: \n");
                scanf("%s", http);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(HTTP(aux), http)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

            case 7:
                printf("Insira o agente: \n");
            //	__fpurge(stdin);
                scanf("%s", agente);
                do{	//strcmp retorna 0 se as strings a serem comparadas forem iguais
                    if(strcmp(AGENTE(aux), agente)==0){
                    printf("\nEndereco encontrado com Sucesso!! \n\n");
                    printf("IP: %s \nUsuario: %s \nData: %s \nMetodo: %s \nPath: %s \nHttp: %s \nAgente: %s \n", IP(aux), USUARIO(aux),DATA(aux),METODO(aux),PATH(aux),HTTP(aux),AGENTE(aux));
                	return aux;
				}
                 aux = POST(aux);
                 }while(aux != NULL);
				break;

            case 8:
            	ativo=0;
                break;

			default:
				printf("Opcao Invalida!!\n");
		}
    }while(ativo);
	return NULL;

}

//----------------------------------------------------------

ListaLogApache *exclui(ListaLogApache *p_L){ //exclui um elemento da lista dado um numero de ip horario e path (((((((((((PERGUNTAR PROFESSOR))))))

	ListaLogApache *aux= busca(p_L);

	if(aux != NULL){
		int verifica;
		printf("\n**** Sera exluido em seguida apos confirmacao: (1-SIM 2-NAO) ****\n");
		scanf("%d",&verifica);
		fflush(stdin);

		// -------- 7) Caminho Duplo --------

		if(verifica==1){
			if(ANT(aux) == NULL){ //verifica se o no a ser retirado eh o primeiro
				ListaLogApache *aux_2 = POST(aux);
				free(aux);
				printf("Elemento removido com sucesso...\n");
				return aux_2;
			}

			else if(POST(aux) == NULL){
				free(aux);
				printf("Elemento removido com sucesso...\n");
				return p_L;
			}
			POST(ANT(aux)) = POST(aux);
			ANT(POST(aux)) = ANT(aux);
			// -------- 1), b) Efeito Colateral --------
			free(aux);
			printf("Elemento removido com sucesso...\n");
			return p_L;
		}
		printf("\nOperacao abortada...\n");
	return p_L;
	}
}

//-------------------Verifica quais estao repetidos quantas vezes------------------------------------------

typedef struct no2{
	char usuario[255];
	int ocorrencia;
	struct no2 *prox;
}noUsuario;
//ACHO QUE SERIA MELHOR CRIAR SÓ UM NO STRING PARA OS DOIS, CÓDIGO FICARIA MENOR E PODERIA USAR EM VARIOS OUTROS
typedef struct no{
	char ip[50];
	int ocorrencia;
	struct no *prox;
}JaTem;

JaTem *Aloca_JaTem(JaTem *p_L, char ip[]){
	JaTem *novo = (JaTem*)malloc(sizeof(JaTem));
	strcpy(IP(novo), ip);		//copiar string
	novo->ocorrencia =0;
	POST(novo) = p_L;
	return novo;
}

noUsuario *alocaUsuario(noUsuario *p_L, char usuario[]){
	noUsuario *novo2 = (noUsuario*)malloc(sizeof(noUsuario));
	strcpy(USUARIO(novo2), usuario);		//copiar string
	novo2->ocorrencia =0;
	POST(novo2) = p_L;
	return novo2;
}

int Repetido(JaTem *lista ,char ip_novo[]){  //essa funcao sera chamada pela repetidos, nela sera inserido uma lista dos IP's e um novo IP, essa func vai verificar se
	JaTem *aux = lista;		   						//esse novo IP ja esta nessa lista, caso sim nao vai contar a ocorrencia do mesmo, pois ja foi feito


	// -------- 7) Caminho Condicionado --------
	if(aux == NULL) return 1;

	for(aux; POST(aux)!=NULL; aux=POST(aux)){
		if(strcmp(IP(aux), ip_novo) == 0){
			// -------- 1), a) Pós Fixada --------
			// -------- 3) Referenciamento --------
			aux->ocorrencia++;
			return 0;
		}
	}
	return 1;
}

int Repetido2(noUsuario *lista ,char usuario_novo[]){
	noUsuario *aux = lista;

	if(aux == NULL) return 1;

	for(aux; POST(aux)!=NULL; aux=POST(aux)){
		if(strcmp(USUARIO(aux), usuario_novo) == 0){
			// -------- 1), c) Aridade Unária --------
			aux->ocorrencia++;
			return 0;
		}
	}
	return 1;
}

void repetidos(ListaLogApache *p_L){
	ListaLogApache *aux = p_L;
	// -------- 1), c) Notação Infixada --------
	noUsuario *novo2 = NULL;
	JaTem *novo = NULL;

	for(aux=p_L; aux != NULL; aux=POST(aux)){
		if(Repetido(novo, IP(aux))){
			novo = Aloca_JaTem(novo, IP(aux));
			novo->ocorrencia++;
		}
		if(Repetido2(novo2, USUARIO(aux))){
			novo2 = alocaUsuario(novo2, USUARIO(aux));
			// -------- 1), c) Comando de Atribuição Unária --------
			novo2->ocorrencia++;
		}

	}

	for(novo; POST(novo) != NULL; novo=POST(novo)){
		printf("\nO IP %s possui %d requisicoes.\n", IP(novo), novo->ocorrencia);
	}
	for(novo2; POST(novo2) != NULL; novo2=POST(novo2)){
		printf("\nO USUARIO %s possui %d requisicoes.\n", USUARIO(novo2), novo2->ocorrencia);
	}

}

//-------------------------------------------------------------

ListaLogApache *desaloca(ListaLogApache *l){
	ListaLogApache *aux = l;
	while(aux != NULL){
		l = POST(aux);
		free(aux); 	//ao liberar o nó aux o ponteiro ant do proximo no ira apontar para NULL
		//aux = l;
	}
	return NULL;
}

//----------------------------------------------------------
		typedef struct noCont{
		char hora[4];
		char IP[50];
		long cont;
		struct noCont *prox;
	}noCont;

	noCont *aloca_noCont(noCont *p_L, char horaRecebida[], char *IP){
		// -------- 4) Expressão Categórica de Tamanho --------
		noCont *novo = (noCont*)malloc(sizeof(noCont));
		strcpy(novo->hora, horaRecebida);		//copiar string
		strcpy(novo->IP, IP);
		novo->cont =0;
		POST(novo) = p_L;
		return novo;
	}

int comparaHora(noCont *lista ,ListaLogApache *p_L){
	noCont *aux = lista;

	if(aux == NULL) return 1;

	for(aux; POST(aux)!=NULL; aux=POST(aux)){
		if(strcmp(aux->hora, p_L->hora) == 0){
			aux->cont++;
			return 0;
		}
	}
		return 1;
}


noCont* verificaMaiorTrafego(ListaLogApache *p_L, int mostrarHorarios){
	ListaLogApache *aux = p_L;
	noCont *novo = NULL;

	for(aux=p_L; aux != NULL; aux=POST(aux)){
		if(comparaHora(novo,aux)){
			novo = aloca_noCont(novo, aux->hora, IP(p_L));
			novo->cont++;
		}
	}

	noCont *temp = novo;  //criando no para comparação

	for(novo; POST(novo) != NULL; novo=POST(novo)){
		if(mostrarHorarios)
			printf("%s H - %ld acessos\n",novo->hora, novo->cont);

		// -------- 1), a) Notação Infixada --------
		if((novo->cont)>(temp->cont))
			temp = novo;
	}

	return temp;
}

void trafego(ListaLogApache *p_L){

	noCont *temp = verificaMaiorTrafego(p_L, 1);

	printf("O horario de maior trafego eh %s h com %ld acessos.\n",temp->hora, temp->cont);

}//END TRAFEGO

// -------- 10) IP mais acessado --------
void MostView(ListaLogApache *p_L){

	noCont *temp = verificaMaiorTrafego(p_L, 0);

	printf("O IP mais acessado no horario de pico foi o %s\n", temp->IP);
}