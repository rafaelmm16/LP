#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define M_PI           3.14159265358979323846  /* pi */

int level_one (double gain){ return (gain>=2000.0 && gain<=5000.0); }
int level_two (double gain) { return (gain>=5000.01 && gain<=10000.0); }
int level_three (double gain) {return (gain>=10000.01 && gain<=15000.0); }
int level_four(double gain) {return (gain>=15000.01 && gain<=50000.0); }
int level_five(double gain) {return (gain>=50000.01 && gain<=100000.0); }

int brief (double stakeholders[], int length, int (*post_sharp) (double)) {
    
    int index, plus = 0;
	for (index = 0; index < length; index++)
	     if ( (*post_sharp) (stakeholders[index]) ) plus++;
	return plus;
}
int main(void) {
    
    int space=20;
    double plays[space]={4500, 3500, 7800, 9000, 12400, 3800, 6000.45, 8765.12, 7000.15, 14750.50, 19800.45, 14900.14, 8000, 12400, 2800, 6000.45, 6765.12, 9000.15, 13770.50, 16900.14};

    double pi;
    pi = M_PI;
    float a = 355.f/113;
    double b = 355.0/113;
    printf("Teste float: %lf\n", pi);
    printf("Teste float: %lf\n",a);
    printf("Teste float: %lf\n",b);

    printf ("%d\n", brief (plays, space, level_one));
    printf ("%d\n", brief (plays, space, level_two));
    printf ("%d\n", brief (plays, space, level_three));
    printf ("%d\n", brief (plays, space, level_four));
    printf ("%d\n", brief (plays, space, level_five));

 }  