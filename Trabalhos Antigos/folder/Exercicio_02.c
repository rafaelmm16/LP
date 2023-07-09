#import <stdio.h>
#import <stdlib.h>

union metros{
    float vetor_m[3]; //0=m 1=cm 2=mm
};
union kilos{
    float vetor_k[3]; //0=mg 1=g 2=kg
};
union litros{
    float vetor_l[2]; //0=ml 1=l
};
union libras{
    float vetor_lb[2]; //0=(16)oncas/p 1lb 1=lb (16 oncas)
};

void main(){
    //metros kilogramas litros libras
    int op, op2;

    puts("=== MENU ===");
    puts("01 - Metros");
    puts("02 - Kilos");
    puts("01 - Litros");
    puts("01 - Libras");

    puts("Selecione uma opcao:");
    scanf("%d",&op0);

    switch(op){
        case 1:{
            union metros p;
        }
        case 2:{

        }
        case 3:{

        }
        case 4:{

        }
    }//FIM SWITCH

    printf("m: %f\n",test.m);
    printf("cm: %f\n", test.cm);
    printf("mm: %f\n", test.mm);
}
