#ifndef SET_H_
#define SET_H_

#include "datatypes.h"


struct STRTNODE {
	int elem;
	struct STRTNODE *left;
	struct STRTNODE *right;
};

int tree_insert(struct STRTNODE **root, int e);
int already_in(struct STRTNODE *root, int e);
void tree_print(int level,struct STRTNODE *root);

#endif /* SET_H_ */
