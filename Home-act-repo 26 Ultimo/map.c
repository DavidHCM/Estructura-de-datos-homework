#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define M 6

struct STRMLNODE {
    char key[60];
    char data[100];
    struct STRMLNODE *next;
};

typedef struct {
    struct STRMLNODE *first;
    struct STRMLNODE *last;
} MAPLIST;

unsigned long long hash(char *s)
{
    int len = strlen(s);
    int i=0;
    unsigned long long retcode = 0;
    char c;

    if(len>12)
        len = 12;

    while(i<len && s[i]!='\0')
    {
        c = toupper(s[i]);
        if(c>='A' && c<='Z')
        {
            retcode = retcode << 5;
            retcode = retcode | (c & 0x1F);
        }
        i++;
    }

    return retcode;
}

void maplist_table_init(MAPLIST *table,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        table[i].first=NULL;
        table[i].last=NULL;
    }
}

void maplist_insert(MAPLIST *list,char *key,char *data)
{
    struct STRMLNODE *ptr = list->first;

    while(ptr!=NULL && strcmp(ptr->key,key)!=0)
        ptr = ptr->next;

    if(ptr==NULL)
    {
        ptr = malloc(sizeof(struct STRMLNODE));
        strcpy(ptr->key,key);
        ptr->next = NULL;
        if(list->first==NULL)
            list->first = ptr;
        else
            list->last->next = ptr;

        list->last = ptr;
    }

    strcpy(ptr->data,data);
}

void map_insert(MAPLIST *map,char *key,char *data)
{
    unsigned long long hashcode = hash(key);
    int p = (int) hashcode % M;

    printf("El código es %016llX\n",hashcode);
    p = (int) (hashcode % M);
    printf("Posición en la tabla(p) es %d\n",p);

    maplist_insert(&map[p],key,data);
}

void maplist_display(MAPLIST list)
{
    struct STRMLNODE *ptr = list.first;

    while(ptr!=NULL)
    {
        printf("<\"%s\",\"%s\"> ",ptr->key,ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


// ...

char *map_get(MAPLIST *m, char *key) {
    unsigned long long hashcode = hash(key);
    int p = (int) hashcode % M;

    struct STRMLNODE *ptr = m[p].first;
    while (ptr != NULL) {
        if (strcmp(ptr->key, key) == 0) {
            return ptr->data;
        }

        ptr = ptr->next;
    }

    return  NULL;
}

void map_destroy(MAPLIST *m) {
    for (int i = 0; i < M; i++) {
        struct STRMLNODE *ptr = m[i].first;
        while (ptr != NULL) {
            struct STRMLNODE *next = ptr->next;
            free(ptr);
            ptr = next;
        }

        m[i].first = NULL;
        m[i].last = NULL;
    }
}
