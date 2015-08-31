#include "queue.h"

/*
 * ARCHIVO:
 *      queue.h
 * 		�ltima modificaci�n: 2007/03/27 (V. Mac�as)
 * --------------------------------------------------------------------------------------
 * DESCRIPCION:
 * 		Este archivo contiene la implementaci�n del TDA PILA 
 * DEPENDENCIAS:
 * MODIFICACIONES:
 *		2004/06/08 (Marisol Villacres):	Version original que define a la pila como una lista
 *		2007/03/27 (V. Mac�as):	Version con nombres en ingl�s.
 */

int queueIsEmpty(Queue *Q){
	return listIsEmpty(Q);
}
Queue *queueNew(){
	return(listNew());
}
void queueEnqueue(Queue *Q, NodeList *newNode){
	listAddNode(Q, newNode);
}
NodeList *queueDequeue(Queue *Q){
	return listRemoveFirst(Q);
}

NodeList *queueDequeuePriority(Queue *Q,cmpfn cmp){
    NodeList *iterator,*selected;

    selected= Q->header;

    if  (selected ==NULL)
            return (NULL);

        for(iterator = selected->next; iterator!=NULL; iterator = iterator->next){
         if(cmp(selected->cont,iterator->cont) ==1)
             selected=iterator;
    }
    listRemoveNode(Q,selected);
    return selected;
 }


NodeList *queuePeekFront(Queue *Q){
	return listGetHeader(Q);
}

NodeList *queuePeekEnd(Queue *Q){
	return listGetLast(Q);
}

int queueGetSize(Queue *Q){
    return listGetSize(Q);
}
