/*
 * list.h
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include "datatypes.h"

#ifndef LIST_H_
#define LIST_H_

struct STR_LIST_NODE {
	TYPE elem;
	struct STR_LIST_NODE *prior,*next;
};


struct STR_LIST {
	struct STRMLNODE *first,*last;
	int size;
};

typedef struct STR_LIST * LIST;

LIST list_create();
void list_add(LIST l,TYPE e);
int list_size(LIST l);
TYPE list_get(LIST l,int pos);
void list_destroy(LIST l);

#endif /* LIST_H_ */
