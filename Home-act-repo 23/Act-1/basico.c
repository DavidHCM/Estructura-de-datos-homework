#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "set.h"

void print_num(TYPE dato);
void destroy(struct STRTNODE *root);
int comp(TYPE a, TYPE b);

int main()
{
    int rando;
    srand(time(NULL));
    SET *numero_ent = set_create(comp, print_num);


    for (int i = 0; i < 10; i++)
    {
        rando = rand() % (100 + 1 - 1) + 1;
        set_add(numero_ent, int_create(rando));

    }

    set_print(numero_ent);
    destroy(numero_ent);
}

void print_num(TYPE dato)
{
    // Reviso que no sea null para no tener problemas
    if(dato != NULL)
    {
        printf("%d\n", *((int *)dato));
    }
}

void destroy(struct STRTNODE *root)
{

    if(root!=NULL)
    {
        tree_destroy(root->left);
        tree_destroy(root->right);

        struct STRTNODE *toremove = root;
        free(toremove);
    }
}


int comp(TYPE a, TYPE b)
{
    int i1 = *((int *) a);
    int i2 = *((int *) b);
    return i1 - i2;
}