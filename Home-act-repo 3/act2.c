#include <stdio.h>
#include <math.h> //Importamos la libreria de math.h para la raiz cuadrada y la funcion de potencia.


 struct STRVEC{
    float x,y;
};

//Funcion unit para calculo de vector unitario
void unit(struct STRVEC *v1)
{
    //Definicion de varibles que accesan al direccion del struct indicado.
    float vlx = v1->x;
    float vly = v1->y;

    //Calculo del vector unitario.
    v1->x = vlx / (sqrt(pow(vlx,2) + pow(vly,2))); //Division entre el valor de x / a la raiz cuadrada de las potencias de x & y.
    v1->y = vly / (sqrt(pow(vlx,2) + pow(vly,2)));


}

int main()
{
    struct STRVEC v1 = {3,4};
    unit(&v1);
    printf("{\"x=\":%.1f,\"y=\":%.1f}",v1.x,v1.y);
}


