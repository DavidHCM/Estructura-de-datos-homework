#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main(){
    char eleccion;
    FILE *fp;
    int numero=0,sent=0;
    int **A,**B;
    A = malloc(DIM*sizeof (int *));
    B = malloc(DIM*sizeof (int *));

    for(int i=0;i<DIM;i++)
    {
        A[i] = malloc(3*sizeof (int ));
    }
    for(int i=0;i<DIM;i++)
    {
        B[i] = malloc(3*sizeof (int ));
    }


    while(sent != 2)
    {
        printf("Que matriz desea inicializar A o B?: ");
        scanf("%c",&eleccion);
        if(eleccion=='A'){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("Posicion [%d][%d]: ",i,j);
                    scanf("%d",&numero);
                    A[i][j]=numero;
                }
            }
            sent += 1;
        }
        else if(eleccion=='B')
        {
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("Posicion [%d][%d]: ",i,j);
                    scanf("%d",&numero);
                    B[i][j]=numero;
                }
            }
            sent += 1;
        }

    }

    fp=fopen("entrada.bin","ab");
    if(fp==NULL)
    {
        fprintf(stderr,"Error al crear archivo\n");
        exit(1);
    }
    for(int i=0;i<DIM;i++)
    {
        fwrite(A[i],sizeof(int),DIM*DIM,fp);

    }

    fclose(fp);

    //-------------------

    fp=fopen("entrada.bin","ab");
    if(fp==NULL)
    {
        fprintf(stderr,"Error al crear archivo\n");
        exit(1);
    }
    for(int i=0;i<DIM;i++)
    {
        fwrite(B[i],sizeof(int),DIM*DIM,fp);

    }

    fclose(fp);

}