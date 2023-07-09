#import <stdio.h>
#import <stdlib.h>

union medida{
    float m;
    float cm;
    float mm;
};
void main(){
    union medida test;

    test.m = 1.8;
    test.cm = 18;
    test.mm = 0;

    printf("m: %f\n",test.m);
    printf("cm: %f\n", test.cm);
    printf("mm: %f\n", test.mm);

}
