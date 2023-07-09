package Aula_25_09_2019_Exer;

import java.lang.Math;
public class TesteException {
	public static void main(String[] args) throws RaizDeNumerosNegativosException{
		int _num01;

		_num01 = 4;
		System.out.println(Math.sqrt(_num01));
		_num01 = 9;
		System.out.println(Math.sqrt(_num01));
		_num01 = 16;
		System.out.println(Math.sqrt(_num01));
		_num01 = -1;
		System.out.println(Math.sqrt(_num01));
		throw new RaizDeNumerosNegativosException("Erro de raiz numero negativo");
	}
}
