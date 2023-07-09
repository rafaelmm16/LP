#include <stdio.h>
#include <stdlib.h>

void f (){
    static int x[10];
}

int count (void){
    static int num = 0;
    num++;
    return num;
}

void main(){
    f();
    printf("%d\n",count());
    printf("%d\n",count());
    printf("%d\n",count());
}
