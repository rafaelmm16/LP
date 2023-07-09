import java.util.HashMap;
import java.util.Map;

public class Tabelas {

    Map<String, Variaveis>  Mapa = new HashMap<String, Variaveis>();

    public void insere(String chave, String valor, String Tipo){

        Variaveis Objeto = new Variaveis();
        Objeto.setNome(chave);
        Objeto.setTipo(Tipo);
        Objeto.setValor(valor);

        Mapa.put(chave, Objeto);
    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////////

    public void imprime (){
        System.out.println("Chave\tValor\tTipo ");
        for (String key :Mapa.keySet()) {
             //Capturamos o valor e o tipo a partir da chave
            String value = Mapa.get(key).getValor();
            String tipo = Mapa.get(key).getTipo();
            System.out.println(key + " \t" + value + " \t"+ tipo);     

        }             
    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////////
    
    public String pesquisa_valor (String chave){

        String Nome=Mapa.get(chave).getValor();
        return Nome;

    }

/////////////////////////////////////////////////////////////////////////////////////////////////////    
    
    public int pesquisa_var(String var){
        
        if(Mapa.get(var)!=null) return 1;
        return 0;
        
    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////////
    
    public String pesquisa_tipo (String chave){

        String Nome=Mapa.get(chave).getTipo();
        return Nome;

    }
    
/////////////////////////////////////////////////////////////////////////////////////////////////////    
    
    public void altera_dados(String chave1, String chave2){
        
        String dado = Mapa.get(chave2).getValor();
        
        Mapa.get(chave1).setValor(dado);
        
        System.out.println("\nEntrou aqui viado\n");
    }
}