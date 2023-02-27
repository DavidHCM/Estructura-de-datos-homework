#include <stdio.h>
// I N T E G R A N T E S:
// BRENDA MARLEM VELA IBARRA
// DAVID HERNANDEZ CAMACHO


int main() {
    float promedio = 0;
    int sumSinc1= 0,sumAsinc1 = 0;
    int examSinc[3] = {};
    int examAsinc[3] = {};
    int b = 0, d = 0, repr = 0;

    printf("\nPor favor ingresa 3 calificaciones de examenes sincronicos: \n");
    for(b=0; b<3;b++){

        printf("Ingresa la calificacion del examen %d: ", b+1);
        scanf("%d",&examSinc[b]);
        sumSinc1 += examSinc[b];
        if (examSinc[b] <= 5){
            repr += 1;
        }

        //Print de prueba para saber que si estoy capturando los datos.
        //printf("%.1f\n",examSinc[b]);
    }

    printf("\nPor favor ingresa 3 calificaciones de examenes asincronicos: \n");
    for(d; d<3;d++){ // @suppress("Statement has no effect")

        printf("Ingresa la calificacion del examen %d: ",d + 1);
        scanf("%d",&examAsinc[d]);
        sumAsinc1 += examAsinc[d];

        //Print de prueba para saber que si estoy capturando los datos.
        //printf("%.1f\n",examAsinc[d]);

    }
    promedio = ((sumSinc1 + sumAsinc1)/6);
    printf("\nTu promedio en respecto a los examenes es: %.1f\n", promedio);


    //print para ver que cuente correctamente los reprobados en el examen sincrono.
    //printf("\nreprobados: %d", repr);

    //Validacion de condiciones
    if ((repr >= 2)||(promedio <= 5.9)) {
        printf("\nEstas reprobado :(\n");
    }else{
        printf("\nEstas aprobado :)\n");
    }

    return 0;
}

