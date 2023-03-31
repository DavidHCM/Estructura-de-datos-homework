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

typedef struct STR_LIST_NODE * ITERATOR;


struct STR_LIST {
	struct STR_LIST_NODE *first,*last,*prefirst,*postlast;
	int size;
};

typedef struct STR_LIST * LIST;

LIST list_create();
void list_add(LIST l,TYPE e);
int list_size(LIST l);
TYPE list_get(LIST l,int pos);
void list_destroy(LIST l);
BOOL list_has_next(ITERATOR iterator);
BOOL list_has_prior(ITERATOR iterator);
ITERATOR list_begin(LIST l);
ITERATOR list_end(LIST l);
ITERATOR list_next(ITERATOR iterator);
ITERATOR list_prior(ITERATOR iterator);
void list_remove(ITERATOR i);


#endif /* LIST_H_ */
