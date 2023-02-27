#include <stdio.h>


void printptrarr(void *a[],int n){
    int i,j;

    for(i=0;i<n;i++){

        printf("%s\t",a[i]);

    }
}

int main() {
    int i;
    char arr[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"};

    char *parr[12]; // {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9],&arr[10],&arr[11]};
    for(i=0;i<12;i++){
        *(parr+i)= (char *) &arr[i];

    }

    printptrarr((void **) parr, 12);

    return 0;
}
