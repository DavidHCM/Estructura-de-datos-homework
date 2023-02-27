#include <stdio.h>
#include <string.h>

void printchar(void *p,char *a)
{
    printf(a,*((char *) p));
    printf("\t");
}

void printint(void *p,char *a)
{
    printf(a,*((int *) p));
    printf("\t");
}

void printshort(void *p,char *a)
{
    printf(a,*((short *) p));
    printf("\t");
}

void printlong(void *p,char *a)
{
    printf(a,*((long *) p));
    printf("\t");

}

void printfloat(void *p,char *a)
{
    printf(a,*(float *) p);
    printf("\t");
}

void printdouble(void *p,char *a)
{
    printf(a,*(double *) p);
    printf("\t");
}

int main() {
    char arr[]={'A','B',100,20,0x4E,50,60,'M','D',0x25,040};
    int i;
    char *parr = arr;

    for(i=0;i<11;i++){
        printchar(parr,  "%c");
        printchar(parr,  "%d");
        printint(parr,"%X");
        printshort(parr,"%X");
        printlong(parr,"%li");
        printfloat(parr,"%f");
        printdouble(parr,"%X");
        printf("\n------------------------------------------------------------------------------------------\n");
        parr++;
    }

    return 0;
}
