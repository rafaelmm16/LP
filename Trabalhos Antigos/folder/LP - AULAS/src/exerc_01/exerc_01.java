package exerc_01;

import java.util.Scanner;

public class exerc_01 {

	public enum Quartenario{FALSO, VERDADEIRO, INTERMEDIARIO, MAXIMO};


	public static void main(String args[]) {

		float nota_1, nota_2, nota_3, media;
		Quartenario status = Quartenario.FALSO;


		Scanner dados = new Scanner (System.in);
		nota_1 = dados.nextFloat();
		nota_2 = dados.nextFloat();
		nota_3 = dados.nextFloat();
		dados.close();
		media = (nota_1+nota_2+nota_3)/3;

		System.out.println("Nota 01:\t"+nota_1+"\nNota 02:\t"+nota_2+"\nNota 03:\t"+nota_3);
		System.out.println("Media:\t"+media+"\n");

		if(media >= 7) {
			if(media != 10) {
				status = Quartenario.VERDADEIRO;
			}else {
				status = Quartenario.MAXIMO;
			}
		}// FIM IF MEDIA 7
		else if(media < 7) {
			if(media >= 5) {
				status = Quartenario.INTERMEDIARIO;
			}else {
				status = Quartenario.FALSO;
			}
		}//FIM ELSE IF

		switch(status){
		case VERDADEIRO:
			System.out.println("APROVADO!");
			break;
		case FALSO:
			System.out.println("REPROVADO!");
			break;
		case INTERMEDIARIO:
			System.out.println("REPROVADO, INTERMEDIARIO");
			break;
		case MAXIMO:
			System.out.println("APROVADO, NOTA MAXIMA");
			break;
		default:
			break;
		}// FIM SWITCH CASE

	}// FIM MAIN

}// FIM CLASSE PRINCIPAL
