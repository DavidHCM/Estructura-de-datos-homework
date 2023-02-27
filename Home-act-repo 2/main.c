#include <stdio.h>
// I N T E G R A N T E S:
// BRENDA MARLEM VELA IBARRA
// DAVID HERNANDEZ CAMACHO

//Intento sin apuntador.
/*
int lenght(char cad[]){
    int a = 0;
    for(int i = 0;i!=-1;i++){
        if(cad[i] == '\0')
        {
            break;
        }
        else
        {
            a++;
        }

    }
    return a;
}
 */

//Intento con apuntador.
int lenght(char cad[]){
    int a = 0,sent = 0;
    char *pcad = cad;

    while(a==0){

        if(pcad[0]!='\0'){
            sent++;
            pcad++;
        }
        else
        {
            a=1;
        }
    }
    return sent;

}

int main() {
    char cad[] = "Hola mundo";
    printf("La longitud de la cadena es: %d\n",lenght(cad));
    return 0;
}
