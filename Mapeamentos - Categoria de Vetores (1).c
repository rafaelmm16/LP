#include <stdio.h>
 
int a = 0 ;  // variável global, aloc. estática

void vetores () {
	 static int x[10]={0,0,1,1,1,1,1,1,1,1}; // vetor estático
         	int y[10]={0,0,1,1,1,1,1,1,1,1}; // vetor semi-estático
     		
       
    printf("VetX[0]: %d VetY[0]: %d ",x[0],y[0]);
    x[0]++;
    y[0]++;
}

 
void incrementa ()
{
          int b = 0 ; // variável local, aloc. automática
   static int c = 0 ; // variável local, aloc. estática
 
   printf ("a: %d, b: %d, c: %d\n", a, b, c) ;
   a++ ;
   b++ ;
   c++ ;
}
 
int main ()
{
  int i ;
 
  for (i=0; i<5; i++){
    incrementa() ;
    vetores(); 	
  }

  return 0 ;
}

