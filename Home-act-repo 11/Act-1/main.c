#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int captura(FILE *,int **);
void fmultiplicacion(FILE *, int **,int **,int **);

int main() {
    int **arr1 = malloc(DIM * sizeof(int *)),**arr2 = malloc(DIM * sizeof(int *)),**arr3 = malloc(DIM * sizeof(int *));
    FILE * fpa1,*fpa2,*fpexit3;

    fpa1 = fopen("C:\\Users\\David\\OneDrive - ITESO\\DED\\Actividades de tarea\\Actividad 10\\a.txt","r");
    if(fpa1 == NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo");
        exit(1);
    }

    fpa2 = fopen("C:\\Users\\David\\OneDrive - ITESO\\DED\\Actividades de tarea\\Actividad 10\\b.txt","r");
    if(fpa2 == NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo");
        exit(1);
    }

    fpexit3 = fopen("C:\\Users\\David\\OneDrive - ITESO\\DED\\Actividades de tarea\\Actividad 10\\c.txt","w");
    if(fpexit3 == NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo");
        exit(1);
    }


    for(int i=0;i<DIM;i++)
    {
        arr1[i] = calloc(DIM, sizeof(int ));
        arr2[i] = calloc(DIM, sizeof(int ));
        arr3[i] = calloc(DIM, sizeof(int ));
    }

    captura(fpa1, arr1);
    captura(fpa2, arr2);
    fmultiplicacion(fpexit3,arr1,arr2,arr3);
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}


int captura(FILE * fpa1,int **arr1)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            fscanf(fpa1,"%d",&arr1[i][j]);
        }
    }
    fclose(fpa1);
    return **arr1;
}

void fmultiplicacion(FILE * fpexit3,int **arr1,int **arr2,int **arr3)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mtemp=0;
            for(int k=0;k<3;k++)
            {
                mtemp += arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = mtemp;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            fprintf(fpexit3,"%d\t",arr3[i][j]);

        }
        fprintf(fpexit3,"\n");
    }

    fclose(fpexit3);
}

