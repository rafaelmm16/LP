#include "funcoesTrab.h"

int main(){
	FILE *arq;
    if((arq = fopen("logs.txt", "r")) == NULL)
	{
		printf("Erro ao abrir arquivo!!!\n\n");
		exit(1);
	}

	int opcao, ativo=1;
	ListaLogApache* LISTA;
	LISTA = Carrega_arquivo(arq);

	do{
		printf("____________________________\n1 - Imprimir Lista\n2 - Busca\n3 - Excluir\n4 - IPs e Usuarios Repetidos\n5 - Maior Trafego\n6 - IP mais alto em horario de pico\n7 - Sair \n____________________________\n");
		fflush(stdin);
		printf("Escolha a opcao:");
		scanf("%d", &opcao);
		// -------- 7) Caminhos Multiplos --------
		switch(opcao){
			case 1:
				imprime(LISTA);
				break;
			case 2:
				buscaImprime(LISTA);
				break;

			case 3:
				LISTA = exclui(LISTA);
				break;

			case 4:
				repetidos(LISTA);  //IP e usuario
				break;

			case 5:
				trafego(LISTA);		//periodo de maior utilizaçao da rede ???
				break;				//pegar a data do registro que tem o maior numero de bytes ???????

			case 6:
				MostView(LISTA);
				break;

			case 7:
				exit(0);
				LISTA = desaloca(LISTA);
				ativo = 0;
				break;

			default:
				printf("Opcao Invalida!!\n");
		}

	}while(ativo);

	free(LISTA);
	fclose(arq);

	return 0;
}
