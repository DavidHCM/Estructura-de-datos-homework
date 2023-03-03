#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main()
{
    int d[DIM][DIM];


    FILE * fp;
    fp = fopen("salida.bin","rb");
    if(fp==NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo\n");
        exit(6);
    }
   fread(d,sizeof (int),DIM*DIM,fp);


    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }

    return 0;
}