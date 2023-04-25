#include <stdio.h>
#define MAX_HEAP 100
#define padre(n) ((n-1)/2)
#define leftChid(n) (n*2+1)
#define rightChid(n) (n*2+2)
#define EMPTY -1

int heap[MAX_HEAP];
int size = 0;

void heap_offer(int num);
void swap(int *a,int *b);
int heap_poll();

int main()
{
    int arr[] = {22,13,15,17,8,26,29,5,14,19,2,7,20,13,29};
    int i,n;

    for(i=0;i<15;i++)
    {
        heap_offer(arr[i]);
    }

    for(i=0;i<15;i++)
    {
        printf("%d\t",heap[i]);
    }

    i=0;

    i=0;
    while((n=heap_poll())!=EMPTY)
    {
        printf("%d\t",n);
    }




    return 0;
}

void heap_offer(int num)
{
    int elem = size;
    // size inicia en 0
    heap[elem] = num;
    size++;

    while(elem>0 && heap[elem]<heap[padre(elem)])
    {
        swap(&heap[elem],&heap[padre(elem)]);
        elem = padre(elem);
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heap_poll()
{
    int retval;
    int last,elem,min;
    if(size==0)
    {
        retval = EMPTY;
    }

    else
    {
        retval = heap[0];
        size--;
        last = size - 1;

        // Poner el último elemento al principio
        heap[0] = heap[last];
        elem=0;
        while(leftChid(elem)<size)
        {
            min = leftChid(elem);

            // Tiene hijo derecho y ademas el hijo derecho
            // es más pequeño que el izquierdo
            if(rightChid(elem)<size && heap[rightChid(elem)]<heap[leftChid(elem)])
                min = rightChid(elem);

            if(heap[elem]>heap[min])
                swap(&heap[elem],&heap[min]);

            elem = min;
        }

    }

    return retval;
}