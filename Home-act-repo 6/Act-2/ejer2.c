#include <stdio.h>
// INTEGRANTES
// DAVID HERNANDEZ CAMACHO

//Declaramos el apuntador void.
typedef void (*ptrfunc)();

//Establecemos la funcion saludar.
void saludar()
{
    printf("Hola\n");
}

//Establecemos una funcion void que su proposito es ejecutar la funcion saludar pero que obtiene como parametro la funcion saludar por medio del aputnador.
void ejecutar(ptrfunc pfunc){
    //Aqui indicamos que tomaremos el elemento almacenado en el apuntador.
    (*pfunc)();
}


int main() {
    //Usamos la funcion ejecutar mandando como parametro la funcion saludar.
    ejecutar(saludar);

    return 0;
}

//Siendo enteramente sincero no estoy seguro si a esto se referia que se tenia que hacer en el ejercicio.
//La verdad me confundio y tambien tuve que investigar un poco sobre esto.