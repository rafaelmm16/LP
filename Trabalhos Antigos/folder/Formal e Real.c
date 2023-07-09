#include <math.h>
#include <stdio.h>
typedef struct coordenadas
{
    int x, y, z;
}coord;
int origem (c)  //FORMA PREVIA DE DECLARACAO
    coord c;
    {
        return (c.x == 1 && c.y == 2 && c.z == 3) ;
    }


void main(){
    coord c = {1, 2, 3};
    printf("%d", origem(c));

}
