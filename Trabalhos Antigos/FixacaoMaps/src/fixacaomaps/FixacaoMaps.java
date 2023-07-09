package fixacaomaps;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
    Desenvolver uma rotina em C++ e Java (pode substituir uma dessa linguagens
    por Python) que utilize Map para inserir um conjunto de informações de
    várias pessoas, incluindo Nome, CPF, Data de Nascimento e Profissão. A chave
    deve ser o CPF. Para isso recomenda-se definir uma classe chamada Pessoas
    com seus atributos. Também, pode ser adequado fazer uso de switch-case para
    apresentar opções de Inserir dados, Pesquisar uma chave e obter os dados
    associados, Alterar dados, Remover registros, Quantidade de registros do
    Map, Imprimir as informações inseridas, e sair. A solução deve ser
    modularizada, construída com métodos para inserir dados, imprimir e busca
    direta por uma chave bem como os demais métodos.
*/

public class FixacaoMaps {
    public static Pessoas lePessoa(){
        Scanner leitura = new Scanner(System.in);
        Pessoas novo;
        String n, dN, p;
        double cpf;
        
        //Leitura dos dados
        System.out.print("Digite o nome: ");
        n = leitura.nextLine();
        
        System.out.print("Digite a profissão: ");
        p = leitura.nextLine();
        
        System.out.print("Digite a data de nascimento (DD/MM/AAAA): ");
        dN = leitura.nextLine();
        
        System.out.print("Digite o CPF: ");
        cpf = leitura.nextDouble();
        
        //Inicialização do objeto com os dados lidos
        novo = new Pessoas(n, p, dN, cpf);      
        
        return novo;
    }
    
    public static void main(String[] args) {
        //Criando map
        Map<Double, Pessoas> mapa_LP = new HashMap<>();
        
        //Declarando variáveis
        int opc;
        double key, verificacao;
        boolean sair = false;
        Pessoas value;
        Scanner leitura = new Scanner(System.in);
        
        while(!sair){
            System.out.println("[1] - Inserir uma pessoa");
            System.out.println("[2] - Pesquisar uma pessoa");
            System.out.println("[3] - Alterar dados de uma pessoa");
            System.out.println("[4] - Remover uma pessoa");
            System.out.println("[5] - Listar quant. de pessoas");
            System.out.println("[6] - Listar todas as pessoas");
            System.out.println("[7] - Sair");
            System.out.print("Digite a opção desejada: ");
            opc = leitura.nextInt();
                        
            switch(opc){
                case 1://inserir dados                    
                    Pessoas teste = lePessoa();
                    //teste.mostraDados();
                    try{
                        mapa_LP.put(teste.getCpf(), teste);
                    }catch(Exception ex){
                        System.out.println("Não foi possível inserir a pessoa desejada!");
                    }
                    
                break;
                case 2://pesquisar uma chave                    
                    System.out.print("Digite a chave da pessoa que deseja encontrar(CPF): ");
                    key = leitura.nextDouble();
                    value = mapa_LP.get(key);
                    try{
                        value.mostraDados();
                        System.out.println("");
                    }catch(Exception ex){
                        System.out.println("Chave não encontrada!\n");
                    }
                break;
                case 3://alterar dados                    
                    System.out.print("Digite a chave da pessoa que deseja alterar(CPF): ");
                    key = leitura.nextDouble();
                    value = mapa_LP.get(key);
                    try{
                        String lixo = leitura.nextLine();//recolhendo lixo
                        //vai tentar obter um valor da chave obtida, se der certo prossegue,
                        //caso a chave seja inválida, ele só mostrará a mensagem de erro
                        verificacao = value.getCpf();
                        
                        //Leitura dos dados
                        System.out.print("Digite o nome: ");//não tá pedindo o nome aqui
                        value.setNome(leitura.nextLine());

                        System.out.print("Digite a profissão: ");
                        value.setProfissao(leitura.nextLine());

                        System.out.print("Digite a data de nascimento (DD/MM/AAAA): ");
                        value.setDataNascimento(leitura.nextLine());
                        
                        //substitui pelo objeto alterado
                        mapa_LP.replace(key, value);
                    }catch(Exception ex){
                        System.out.println("Chave não encontrada!\n");
                    }   
                break;
                case 4://remover registros                    
                    System.out.print("Digite a chave da pessoa que deseja apagar(CPF): ");
                    key = leitura.nextDouble();
                    try{
                        mapa_LP.remove(key);
                    }catch(Exception ex){
                        System.out.println("Não foi possível apagar, pois a chave não foi encontrada!");
                    }  
                break;
                case 5://Quant de dados no map                    
                    System.out.println("Atualmente, temos " + mapa_LP.size() + " pessoas cadastradas no momento.\n");    
                break;
                case 6://imprimir todas as informações inseridas
                    
                    if(mapa_LP.size()>0){
                        for(Double chave: mapa_LP.keySet()){
                            Pessoas imp = mapa_LP.get(chave);
                            imp.mostraDados();
                            System.out.println("");
                        }
                    }
                    else{
                        System.out.println("Não há pessoas inseridas ainda!\n");
                    }                      
                break;
                case 7://sair                                        
                    System.out.println("Você saiu!");
                    sair = true;
                break;
                default:                    
                    System.out.println("Opção inválida!\n");
                ;
            }
        }
    }
    
}
