package Aula_25_09_2019;

public class TratamentosDeErros {
	public static void main(String[] args) {
		
		//PRIMEIRO ERRO
		/*
		String var = "linguagens de Programacao";
		try {
			Integer i = new Integer(var);
			System.out.println("A variavel i vale " + i);
		}
		catch(NumberFormatException Execao) {
			System.out.println("Nao eh possivel atribuir a string " + var + "a um Objeto inteiro.\n" + "A seguinte Mensagem foi retornada:\n\n" + Execao.getMessage());
		}
		*/
		
		//SEGUNDO ERRO
		int vet[] = new int[12];
		try {
			for(int i=0; i <= 15; i++) {
				vet[i] = i;
				System.out.println(i);
			}
		}catch(ArrayIndexOutOfBoundsException excecao) {
			System.out.println("Tentativa de acessar indice inexistente de vetor! Indice do erro no vetor." + excecao.getMessage());
		}
		
	}
	
}
