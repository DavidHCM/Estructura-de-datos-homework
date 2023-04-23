#include <stdlib.h>
#include <stdio.h>
#include "set.h"

/* Funciones para el manejo de los árboles */

int tree_insert(struct STRTNODE **root, int e)
{
	int inserted = 0;
	if(*root==NULL)
	{
		*root = malloc(sizeof(struct STRTNODE));
		(*root)->elem = e;
		(*root)->left = NULL;
		(*root)->right = NULL;
		inserted = 1;
	}
	else if(e < (*root)->elem)
		inserted = tree_insert(&(*root)->left,e);
	else if(e > (*root)->elem)
		inserted = tree_insert(&(*root)->right,e);

	return inserted;
}

int already_in(struct STRTNODE *root, int e){
	if(root->elem == e){
		return 1;
	}
	else if((e < root->elem) && (!(root->left == NULL))){
		return already_in(root->left, e);
	}
	else if((e > root->elem) && (!(root->right == NULL))){
		return already_in(root->right, e);
	}

	return 0;
}

void tree_print(int level,struct STRTNODE *root)
{
	int i;
	if(root!=NULL)
	{
		tree_print(level+1,root->right);

		for(i=0;i<level;i++)
			printf("\t");
		printf("%d\n",root->elem);

		tree_print(level+1,root->left);
	}
}