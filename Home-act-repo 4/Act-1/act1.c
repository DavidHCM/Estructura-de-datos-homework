#include <stdio.h>
#include <string.h>


void sortnames(void *p,int rows){
    int i,j,a;
    char *s = p;
    char temp[10];
    for(i=0;i<rows;i++){
        for(j=0;j<10;j++){

            if((strcmp(s, (s+10)))>=1){
                strcpy(temp ,s);
                strcpy(s, s+10);
                strcpy(s+10,temp);

            }
            s += rows;
            }

        s = p;
        }


}

void printnames(char nombres[][10],int rows){
    int i;

    for(i=0;i<rows;i++){
        printf("%s\n",nombres[i]);
    }
}

int main() {
    char nombres[10][10]={"Juan","Jose","Gaby","Maria","Karla","Luis","Antonio","Cecilia","Roberto","Francisco"};
    printf("Nombres sin ordenar: \n");
    printnames(nombres,10);
    printf("\n--------------------\n");
    sortnames(nombres,10);
    printf("Nombres ordenados: \n");
    printnames(nombres,10);
    return 0;
}
