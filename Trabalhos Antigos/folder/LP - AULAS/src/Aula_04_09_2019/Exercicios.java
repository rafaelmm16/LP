package Aula_04_09_2019;

public class Exercicios {
	public static void main(String[] args) {
		int [] [] a = new int [5][];
		for(int i=1; i<a.length; i++) {;
			a[i] = new int [i+1];
			
		}
		a[1][1] = 1;
		a[2][2] = 2;
		
		System.out.println(a[1][1] +" "+ a[2][2]+" "+ a[1][2]);
	
		//	System.out.println(a[0][0]);
	}
}
