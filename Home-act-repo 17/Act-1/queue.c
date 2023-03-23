/*
 * queue.c
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */
#include <stdio.h>
#include "queue.h"

QUEUE queue_create()
{
	QUEUE new = malloc(sizeof(struct STR_QUEUE));

	new->front = NULL;
    new->rear = NULL;
	new->size = 0;

	return(new);
}

void queue_offer(QUEUE q,TYPE e)
{

    struct STR_QUEUE_NODE * new = malloc(sizeof(struct STR_QUEUE_NODE));
    new->elem = e;

    if(q->front == NULL)
    {
        q->rear = new;
        q->front = new;
        q->size = q->size + 1;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
        q->rear->next = NULL;
        q->size = q->size + 1;
    }
}

BOOL queue_empty(QUEUE q)
{
	return (q->front == NULL);
}

TYPE queue_poll(QUEUE q)
{
    TYPE elem = NULL;
    struct STR_QUEUE_NODE *remove = NULL;

    if(q->front !=NULL)
    {
        remove = q->front;
        elem = q->front->elem;
        q->front = q->front->next;
        q->size = q->size - 1;
        free(remove);
    }
    return elem;
}

TYPE queue_peek(QUEUE q)
{
    TYPE toreturn = NULL;
    if(q->rear!=NULL)
    {
        return (q->front->elem);
    }
    else
    {
        return toreturn;
    }
}

void queue_destroy(QUEUE q)
{
	while(!queue_empty(q))
		queue_poll(q);
	free(q);
}


