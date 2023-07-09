#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

// Alterando o construtor da classe
class Pessoa
{
public:
    string cpf;
    string nome;
    string dataNascimento;
    string profissao;
};

// Criando map
map<string, Pessoa>
    mapPessoa;

void menuPrincipal()
{
    printf("\n[1] - Inserir pessoa");
    printf("\n[2] - Pesquisar pessoa");
    printf("\n[3] - Alterar dados");
    printf("\n[4] - Remover pessoa");
    printf("\n[5] - Listar quant. de pessoas");
    printf("\n[6] - Listar todas as pessoas");
    printf("\n[0] - Sair");
    printf("\nDigite a opção desejada: ");
}

void Alterar()
{
    printf("\n Qual informação deseja alterar");
    printf("\n 1 - Nome");
    printf("\n 2 - Data de nascimento");
    printf("\n 3 - CPF");
    printf("\n 4 - Profissão");
    printf("\n 0 - SAIR");
    printf("\nEscolha a opcao:\t");
}

int main()
{
    // Declarando variáveis
    int opcao, opcao2;
    string cpf, nome, dataNascimento, profissao, cpfnv;

    map<string, Pessoa>::iterator it;

    do
    {
        menuPrincipal();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1: // Inserir dados
            printf("\n Digite o nome: ");
            cin >> nome;
            printf("Digite o CPF: ");
            cin >> cpf;
            printf("Digite a data de nascimento: ");
            cin >> dataNascimento;
            printf("Digite a profissao: ");
            cin >> profissao;

            mapPessoa.insert(pair<string, Pessoa>(cpf, {cpf, nome, dataNascimento, profissao}));
            break;

        case 2: // Pesquisar uma chave e obter os dados associados
            printf("\n Informe o CPF (chave) que deseja buscar: ");
            cin >> cpf;

            it = mapPessoa.find(cpf);
            if (it != mapPessoa.end())
            { // caso não tenha encontrado a chave, it está apontando para além do último elemento de mapPessoa
                cout << "\n Nome: " << it->second.nome;
                cout << "\n CPF: " << it->second.cpf;
                cout << "\n Data Nascimento: " << it->second.dataNascimento;
                cout << "\n Profissão: " << it->second.profissao;
            }
            else
            { // caso não tenha um chave no
                cout << "CPF informado não encontrado. Tente novamente!\n";
            }
            break;

        case 3: // Alterar dados
            printf("\n Informe o CPF (chave) que deseja alterar: ");
            cin >> cpf;
            it = mapPessoa.find(cpf);
            if (it != mapPessoa.end())
            { // caso não tenha encontrado a chave, it está apontando para além do último elemento de mapPessoa
                cout << "\n Essas são as informações do registro:";
                cout << "\n Nome: " << it->second.nome;
                cout << "\n CPF: " << it->second.cpf;
                cout << "\n Data Nascimento: " << it->second.dataNascimento;
                cout << "\n Profissão: " << it->second.profissao;

                Alterar();
                cin >> opcao2;
                if (opcao2 == 1)
                {
                    cout << "Novo Nome: ";
                    cin >> nome;
                    mapPessoa[cpf].nome = nome;
                }
                if (opcao2 == 2)
                {
                    cout << "Nova data de nascimento: ";
                    cin >> dataNascimento;
                    mapPessoa[cpf].dataNascimento = dataNascimento;
                }
                if (opcao2 == 3)
                {
                    cout << "Novo CPF:";
                    cin >> cpfnv;
                    mapPessoa.insert(pair<string, Pessoa>(cpfnv, {cpfnv, mapPessoa[cpf].nome, mapPessoa[cpf].dataNascimento, mapPessoa[cpf].profissao}));
                    mapPessoa.erase(cpf);
                }
                if (opcao2 == 4)
                {
                    cout << "Nova Profissão:";
                    cin >> profissao;
                    mapPessoa[cpf].profissao = profissao;
                }
            }
            else
            { // caso não tenha um chave no
                cout << "CPF informado não encontrado. Tente novamente!\n";
            }
            break;
        case 4: // Remover registro
            printf("\n Informe o CPF (chave) que remover do: ");
            cin >> cpf;

            it = mapPessoa.find(cpf);
            if (it != mapPessoa.end())
            { // caso não tenha econtrado a chave, it está apontando para além do último elemento de mapPessoa
                mapPessoa.erase(cpf);
                cout << "Removido com sucesso! \n";
            }
            else
            { // caso não tenha um chave no
                cout << "CPF informado não encontrado. Tente novamente!\n";
            }
            break;

        case 5: // Quantidade de registros do MAP
            cout << "Atualmente constam " << mapPessoa.size() << " elementos na base de dados.\n";
            break;

        case 6: // Imprimir Map
            if (mapPessoa.size() > 0)
            {
                for (auto it : mapPessoa)
                {
                    cout << "\n Nome: " << it.second.nome;
                    cout << "\n CPF: " << it.second.cpf;
                    cout << "\n Data Nascimento: " << it.second.dataNascimento;
                    cout << "\n Profissão: " << it.second.profissao;
                    cout << "\n";
                }
            }
            else
            {
                cout << "Nenhum cadastro encontrado!''.\n";
            }
            break;
        }
    } while (opcao != 0);

    return 0;
}
