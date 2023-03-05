#include <stdio.h>
#include <stdlib.h>
#define DIM 3


int main()
{
    FILE * fp;
    int **a,**b,**c;

    a = malloc(DIM*sizeof (int *));
    b = malloc(DIM*sizeof (int *));
    c = malloc(DIM*sizeof (int *));

    for(int i=0;i<DIM;i++)
    {
        a[i] = malloc(3*sizeof (int ));
        b[i] = malloc(3*sizeof (int ));
        c[i] = malloc(3*sizeof (int ));
    }



    fp = fopen("entrada.bin","rb");
    if(fp==NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo\n");
        exit(1);
    }
    for(int i=0;i<DIM;i++)
    {
        fread(a[i], sizeof (int),DIM*DIM,fp);

    }
    for(int i=0;i<DIM;i++)
    {
        fread(b[i], sizeof (int),DIM*DIM,fp);

    }



    //----------------------------------

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mtemp=0;
            for(int k=0;k<3;k++)
            {
                mtemp += a[i][k] * b[k][j];
            }
            c[i][j] = mtemp;
        }
    }
    free(a);
    free(b);

    fclose(fp);
    //----------------------------------
    //----------------------------------
    //----------------------------------
    //----------------------------------
    fp = fopen("salida.bin","wb");
    if(fp==NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo\n");
        exit(3);
    }
    for(int i = 0;i<DIM;i++)
    {
        fwrite(c[i],sizeof (int),DIM*DIM,fp);
    }

    fclose(fp);
    free(c);



    return 0;
}

