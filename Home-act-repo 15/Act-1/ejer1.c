#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 20

struct STRNODE {
    int num;
    struct STRNODE *next;
};

typedef struct {
    struct STRNODE *first;
    struct STRNODE *last;

} LIST;

#define LISTINIT {NULL,NULL}

void insert(LIST *list,int num)
{
    struct STRNODE *new = malloc(sizeof(struct STRNODE));

    new->num = num;
    new->next = NULL;

    if(list->first==NULL)
    {
        list->first = new;
    }
    else
    {
        list->last->next = new;
    }
    list->last = new;
}


int found(LIST list,int num)
{
    struct STRNODE *new = NULL;
    new = list.first;
    while(new!=NULL && new->num != num)
    {
        new = new->next;

        if(new == NULL)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
}
void display(LIST list)
{
    struct STRNODE *new = NULL;
    new = list.first;
    while(new != NULL)
    {
        printf("%d\n",new->num);
        new = new->next;
    }
}
void destroy(LIST list)
{
    struct STRNODE *new = NULL,*todestroy = NULL;

    new=list.first;
    while(new!=NULL)
    {
        todestroy = (struct STRNODE *) new;
        new = new->next;
        free(todestroy);
    }
}

//=========================================================

int main()
{
    LIST l = LISTINIT;
    int i,n;

    srand(time(NULL));

    for(i=0;i<LIMIT;i++)
    {
        n = rand() % LIMIT;
        if(!found(l,n))
        {
            insert(&l,n);
        }
    }

    display(l);
    destroy(l);
}