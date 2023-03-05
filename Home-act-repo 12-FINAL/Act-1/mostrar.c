#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main()
{
    int **d;

    d = malloc(DIM*sizeof (int *));

    for(int i=0;i<DIM;i++)
    {
        d[i] = malloc(3*sizeof (int ));
    }



    FILE * fp;
    fp = fopen("salida.bin","rb");
    if(fp==NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo\n");
        exit(6);
    }

    for(int i=0;i<DIM;i++)
    {
        fread(d[i],sizeof (int),DIM*DIM,fp);
    }

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