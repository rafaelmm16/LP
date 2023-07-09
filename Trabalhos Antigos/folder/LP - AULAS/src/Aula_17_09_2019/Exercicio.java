package Aula_17_09_2019;

import java.util.Scanner;

public class Exercicio {
	private static float num1;
	private static float num2;

	static void setNum1(float a) {
		num1 = a;
	}
	static void setNum2(float b) {
		num2 = b;
	}
	float getNum1() {
		return num1;
	}
	float getNum2() {
		return num2;
	}

	public static void main(String[] args) {
		
		Scanner entrada = new Scanner (System.in);
		System.out.println("Entre com o primeiro valor");
		Exercicio.setNum1(entrada.nextFloat());
		System.out.println("Entre com o segundo valor");
		Exercicio.setNum2(entrada.nextFloat());
		entrada.close();
		
		Exercicio.getNum1 > Exercicio.getNum2 ? vb printf("\nSubtracao:\t%.2f\n",subtracao(a,b)) & printf("\nSoma:\t%.2f\n",soma(a,b)) : printf("\nDivisao:\t%.2f\n",divisao(a,b)) & printf("\nSoma:\t%.2f\n",soma(a,b));

		
	}
}
