
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

public class Main
{
	public static void main(String[] args) {
	Tabelas tabela=new Tabelas();
        String Nome = "Entrada.txt";
        System.out.println("Conteudo do Arquivo .txt");
        try{
            FileReader arq = new FileReader(Nome);
            BufferedReader LerArq = new BufferedReader(arq);
            String linha = LerArq.readLine();
            //System.out.println(linha);
            String marcador, marcador_var, var="";
            //Percorre todas as linhas do arquivo
             while (linha!=null){
                    marcador="";
                    String Tipo="";                    
                    String Identificador="";
                    String Valor="";
                    int i=0;
                    //Pega o tipo da variável
                    while(!marcador.equals(" ")){
                       if(!marcador.equals(" ")) 
                        marcador = String.valueOf(linha.charAt(i));
                        Tipo=Tipo.concat(marcador);
                        i++;
                    }
                    
                    
                    //Pega o identificador
                    while(!marcador.equals(":")){
                        marcador = String.valueOf(linha.charAt(i));
                       if(!marcador.equals(":")) //para não pegar o último marcador da testagem ":"
                           Identificador=Identificador.concat(marcador);
                        
                        //Chave=Chave.concat(marcador)
                        i++;
                        
                    }
                    
                    System.out.println(var);
                                       
                    i++;//Adiciona 1 porque além do caracter : tem o caracter =
                    //Pega o conteúdo do identificador
                    while(!marcador.equals(";")){
                        marcador = String.valueOf(linha.charAt(i));
                        if(!marcador.equals(";")) //para não pegar o último marcador da testagem ";"
                            Valor=Valor.concat(marcador);
                        i++;
                    }
                    linha=LerArq.readLine();
                    tabela.insere(Identificador, Valor, Tipo);
                    
             }                   
            }        
              catch (IOException e){
            System.err.printf("Erro na abertura do Arquivo: %s", e.getMessage());
        }
             tabela.imprime();
             String pesq="NUM3";
             if(tabela.pesquisa_var(pesq)==1){
                 System.out.println(tabela.pesquisa_valor(pesq));
                 System.out.println(tabela.pesquisa_tipo(pesq));  
             }
             else
              System.out.println("Variavel nao definida na tabela de simbolos");
               
  }
}
