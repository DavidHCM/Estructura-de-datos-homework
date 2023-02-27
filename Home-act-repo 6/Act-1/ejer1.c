#include <stdio.h>
// INTEGRANTES
//DAVID HERNANDEZ CAMACHO

typedef int (*func_a) (int,int);

//Funcion void que imprimira el valor triple de la funcion obtenida.
void imprimirrriple(int a){
    printf("El valor triple es: %d\n",a*3);
}

//Funcion void que imprimira el valor doble de la funcion obtenida.
void imprimirdoble(int a){
    printf("El valor doble es: %d\n",a*2);
}

//Funcion de sumar que obtendra dos valores y retornara la suma de los dos.
int sumar(int a, int b){
    return a+b;
}

//Funcion de restar que obtendra dos valores y retornara la resta de los dos.
int restar(int a, int b){
    return a-b;
}



int main() {
    //Definicion de arreglo de apuntador donde vamos a hacer un arreglo a para los que no retornan valor y un arreglo b para los que si retornan valor.
    func_a (*pfunc_a[]) (int,int) = {imprimirdoble,imprimirrriple};
    func_a (*pfunc_b[]) (int,int) = {sumar, restar};
    int a=10,b=5,i,res;
    //Igualamos un apuntador al arreglo de apuntador correspondiente
    func_a *ppfunc_a = pfunc_a;
    func_a *ppfunc_b = pfunc_b;

    //Ciclo for para recorrer el apuntador de arreglo de apuntadores.
    for(i=0;i<2;i++){
        //Aqui mandamos los valores a evaluar.
        (*ppfunc_a)(10,5);
        //Sumamos una posicion en arreglo para poder pasar al siguiente apuntador.
        ppfunc_a++;
    }

    for(i=0;i<2;i++){
        //Aqui mandamos los valores a evaluar.
        res = (*ppfunc_b)(10,5);
        //Se imprime el resultado de la operacion obtenida.
        printf("El resutado de la operacion es: %d\n",res);
        //Sumamos una posicion en arreglo para poder pasar al siguiente apuntador.
        ppfunc_b++;
    }



    return 0;
}
