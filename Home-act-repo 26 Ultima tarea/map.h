//
// Created by David on 12/05/2023.
//

#ifndef HOME_ACT_REPO_26_ULTIMO_MAP_H
#define HOME_ACT_REPO_26_ULTIMO_MAP_H
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct STRMLNODE {
    char key[60];
    char data[80];
    struct STRMLNODE *next;
};

typedef struct STR_LIST MAPLIST;
unsigned long long hash(char *s);
void maplist_table_init(MAPLIST *table,int m);
void maplist_insert(MAPLIST *list,char *key,char *data);
void maplist_display(MAPLIST list);
void map_insert(MAPLIST *map,char *key,char *data);
int map_get(MAPLIST *m, char *key);
void map_destroy(MAPLIST *m);

#endif //HOME_ACT_REPO_26_ULTIMO_MAP_H
