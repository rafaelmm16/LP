import java.util.ArrayList;

public class Main
{
      	 
	public static void main(String[] args) {
	
	ArrayList<String> lista = new ArrayList<String>(); 
	
	lista.add("Abacaxi");
	lista.add("Laranja"); 
	lista.add("Pera"); 
    /* Quantos elementos quiser, desde que caiba na memória  */ 
    
    for ( String s : lista )
       System.out.println(s);

	}
}

