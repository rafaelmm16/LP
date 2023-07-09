package Aula_25_09_2019_Exer;
//DESENVOLVA EM JAVA UMA NOVA EXCECAO PARA IDENTIFICAR
//TENTATIVAS DE RAIZ QUADRADA DE NUMEROS NEGATIVOS.
//FACA UMA ESTRUTURA TESTE PARA ESTA NOVA EXCECAO.

public class RaizDeNumerosNegativosException extends RuntimeException {
	public RaizDeNumerosNegativosException(String message) {
		super(message);
	}

}
