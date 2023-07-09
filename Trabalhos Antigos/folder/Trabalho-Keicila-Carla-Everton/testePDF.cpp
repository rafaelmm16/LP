#include <iostream>
#include <iostream>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include

using namespace std;

void gerarPDF(){
    std::string line;
    pdf::Document doc(pdf::create_file("RegistrosLogs.pdf"));
    //pdf:: jag_Document doc(pdf::create_file("RegistrosLogs.pdf"));
    doc.page_start(597.6, 848.68);
    jag::pdf Font courier = doc.font_load("standard; name=Courier; size=8");
    doc.page().canvas().text_font(courier);
    doc.page().canvas().text(50, 800, "================================================================================================");
    doc.page().canvas().text(50, 790, "                                 RELATORIO DE GERACAO DE ERRO                                    ");
    doc.page().canvas().text(50, 780, "================================================================================================");
    int aux=770;

    std::ifstream myfile ("logs.dat");
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
    char* result = new char[line.length()+1];
    strcpy(result,line.c_str());


      doc.page().canvas().text(50, aux, result);
       aux = aux-10;

    }
    myfile.close();
    }
    doc.page_end();
    doc.finalize();


}


int main(int argc, char** const argv)
{
    int opcao;
	do{
	std::cout <<"\n\nEscolha a Operacao: \n";
	std::cout <<"1 - Visualizar Erros \n";
	std::cout <<"2 - Gerar PDF \n";
	std::cout <<"0 - Sair \n\n";
    std::cout <<"Opcao:";
	std::cin>> opcao;

   if(opcao == 1){
				std::string line;
                  std::ifstream myfile ("logs.dat");
                  if (myfile.is_open())
                  {
                    while ( getline (myfile,line) )
                    {
                      std::cout << line << "\n";
                    }
                    std::cout << "\n";
                    //system("pause");
                    myfile.close();

                    }

    }

		if(opcao == 2){
				gerarPDF();
				std::cout << "PDF Gerado Com Sucesso!" << "\n";
				//system("pause");


        }
    system("cls");
    }while(opcao!=0);

    return 0;
}
