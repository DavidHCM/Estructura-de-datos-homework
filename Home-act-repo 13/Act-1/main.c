#include <stdio.h>

struct STRALUM {
    struct STRALUM *siguiente;
    char nombre[30];
    char apellido[30];
    int expediente;

};




void insert(struct STRALUM **ptriniciolista,struct STRALUM *n)
{
    struct STRALUM *ptr = NULL;



    if(*ptriniciolista == NULL)
    {
        *ptriniciolista = n;
    }
    else
    {

        ptr = *ptriniciolista;
        while(ptr->siguiente!=NULL)
        {
            ptr = ptr->siguiente;
        }
        ptr->siguiente=n;
    }

}

void printdates(struct STRALUM *d)
{
    struct STRALUM*ptr=d;

    while(ptr!=NULL)
    {
        printf("%d\t%s \t %s\n",ptr->expediente,ptr->nombre,ptr->apellido);
        ptr = ptr->siguiente;
    }
}

int main() {

    struct STRALUM al1 = {NULL,"David Rodrigo","Leon",744025};
    struct STRALUM al2 = {NULL,"Ximena","Isaac",739032};
    struct STRALUM al3 = {NULL,"Luis Fernando","Chavez",734822};
    struct STRALUM al4 = {NULL,"Renata","Tejeda",739500};
    struct STRALUM al5 = {NULL,"Harel","Olguin",742621};
    struct STRALUM al6 = {NULL,"Brenda","Vela",740732};

    struct STRALUM *iniciolista = NULL;
    struct STRALUM *ptr;
    insert(&iniciolista,&al1);
    insert(&iniciolista,&al2);
    insert(&iniciolista,&al3);
    insert(&iniciolista,&al4);
    insert(&iniciolista,&al5);
    insert(&iniciolista,&al6);

    ptr = iniciolista;

    printdates(iniciolista);

    return 0;
}
