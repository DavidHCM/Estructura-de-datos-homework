#include <stdio.h>
#include <stdlib.h>
#define DIM 3


int main()
{
    FILE * fp;
    int a[DIM][DIM],b[DIM][DIM],c[DIM][DIM];
    fp = fopen("entrada.bin","rb");
    if(fp==NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo\n");
        exit(1);
    }
    fread(a,sizeof(int),DIM*DIM,fp);
    fread(b,sizeof(int),DIM*DIM,fp);

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
    fwrite(c,sizeof (int),DIM*DIM,fp);
    fclose(fp);




    return 0;
}

