#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMCONS 2

typedef struct strp{
    int VD;
    struct strp *sig;
} PN;

typedef struct LENC{
    PN *VD1,*VD2;
} LST;


void listAdd(LST *lista,int numrecp)
{
    PN *NNum = malloc(sizeof (PN));
    NNum -> VD = numrecp;
    NNum -> sig = NULL;

    if(lista->VD1 == NULL)
    {
        lista->VD1 = NNum;
    }
    else
    {
        lista->VD2->sig = NNum;
    }

    lista->VD2=NNum;
}


int primo(int indc)
{
    for(int j=NUMCONS;j *j <= indc ;j++)
    {
        if(indc%j == 0)
        {
            return 1;
        }
    }
    return -1;
}

int main()
{
    clock_t inicio,fin;
    LST listaTep = {NULL,NULL};
    int sentLim = 0;
    printf("Ingrese el limite del numero a primos: ");
    scanf("%d",&sentLim);
    inicio =clock();

    for(int i=NUMCONS;i<sentLim;i++)
    {
        if(primo(i) == -1)
        {
            listAdd(&listaTep,i);
        }
    }

    PN *printList = malloc(sizeof (PN));
    printList = listaTep.VD1;
    while(printList != NULL)
    {
        printf("\n%d",printList->VD);
        printList = printList -> sig;
    }

    fin =clock();
    printf("\nTiempo = %5.2f segundos",(fin-inicio)/1000.0);

}