#include <stdio.h>
#include <time.h>
#include "set.h"

int main()
{

int i,n;
struct STRTNODE *root=NULL;

srand(time(NULL));

printf("Numeros generados\n");
for(i=0;i<15;i++)
{
	n = rand() % 6 + 15;
	printf("%d\t",n);
	tree_insert(&root, n);
}

printf("\n\nArbol binario:\n");
tree_print(0,root);

n = rand() % 21;
int a = already_in(root, n);

if(a == 1){
	printf("\nEl numero %d esta en la lista\n", n);
}
else{
	printf("\nEl numero %d no esta en la lista\n", n);
}

system("pause");
return 0;
}