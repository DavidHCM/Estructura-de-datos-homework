#include <stdio.h>
#include <math.h>
//INTEGRANTES
//DAVID HERNANDEZ CAMACHO

//Defini dos constantes para hacer mas sencillo la lectura.
#define x1 10000
#define x2 20000


//Funcion islinear donde recibe el apuntador de la funcion en el elemento que vaya el ciclo for.
int islinear(int (*Function2D)(int)){
    int a,b;
    double res;
    //Igualamos un valor de la funcion en el que va el ciclo for y se evalua con los siguientes parametros.
    a = Function2D(x1);
    b = Function2D(x2);

    //Dividimos los resultados que obtuvimos de los parametros.
    res = b / a;
    //Retornamos un valor sea true o false dependiendo si se encuentra en el rango o no de valores.
    return ((res > 1.99 ) && (res < 2.01))? 1 : 0 ;
}

//Funcion isquadratic que tiene el mismo funcionamiento que la funcion anterior.
int isquadratic(int (*Function2D)(int)){
    int a,b;
    double res;

    //Igualacion de valores dela funcion que obtenemos al evaluarla las funciones dentro del arreglo de apuntador de funciones
    a = Function2D(x1);
    b = Function2D(x2);
    //Dividimos el resultado de las evaluaciones.
    res = b / a;

    //Retornamos un valor true o false dependiendo de la evaluacion si se encuentra en el intervalo de valores.
    return ((res > 3.98 ) && (res < 4.02))? 1 : 0 ;
}

//Funcion de F1(x)
int f1(int x){
    int res;
    res = ((4*x)-2);
    return res;

}

//Funcion de F2(x)
int f2(int x){
    int res;
    res = ((3*pow(x,2))-(2*x+4));
    return res;

}

//Funcion de F3(x)
int f3(int x){
    int res;
    res = ((6*sqrt(x))+2);
    return res;
}



int main() {
    //Creamos un arreglo de apuntador a funciones indicadas de f1,f2,f3.
    int (*parray_a[]) (int) = {f1,f2, f3};
    int i,f,g;

    //Creamos un ciclo for que recorrera todo el arreglo de funciones y que toma como argumento las funciones que vayan en el ciclo for.
    for(i=0;i<3;i++){
        f = islinear(parray_a[i]);
        //Ternario que determina si el valor al ser mayor que 1 es lineal o no.
        (f == 1)? printf("Es lineal. ")  : printf("No es lineal. ");

        g = isquadratic(parray_a[i]);
        //Otro ternario apra isquadratic que determina si el valor es mayor que 1 es cuadratico
        (g == 1)? printf("Es cuadratico\n") :  printf("No es cuadratico\n") ;
    }

    return 0;
}
