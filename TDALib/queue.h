#ifndef QUEUE_H
#define QUEUE_H

/*
 * ARCHIVO:
 *      queue.h
 * 		�ltima modificaci�n: 2007/03/27 (V. Mac�as)
 * --------------------------------------------------------------------------------------
 * DESCRIPCION:
 * 		Este archivo contiene la interfaz del TDA COLA (Queue) 
 * DEPENDENCIAS:
 *		List.h Definici�n de TDA List, ya que la Queue es una lista
 * MODIFICACIONES:
 *		2004/06/08 (Marisol Villacres):	Version original que define a la cola como una lista
 *		2007/03/27 (V. Mac�as):	Version con nombres en ingl�s.
 */

#include "list.h"


typedef List Queue;

/*
 * Funcion: queueIsEmpty
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * if(Queue_isEmpty(Q))...
 * Esta operacion recibe una cola y determina si esta o no vacia
 */
int queueIsEmpty(Queue *St);
/*
 * Funcion: Queue_New
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * Q = Queue_New()
 * Esta operacion crea una nueva Cola
 */
Queue *queueNew();
/*
 * Funcion: queueEnqueue
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * NodeList *nuevo;
 * Queue_Push(Q, nuevo);
 * Esta operacion recibe una Cola y aumenta al elemento nuevo
 * al final de la misma
 */
void queueEnqueue(Queue *St, NodeList *newNode);

/*
 * Funcion: queueDequeue
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * NodeList *nuevo;
 * nuevo = Queue_Pop(Q)...
 * Esta operacion recibe una Cola y retira de la misma
 * el elemento del inicio, retornandolo
 */
NodeList *queueDequeue(Queue *St);

/*
 * Funcion: queueDequeuePriority
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * NodeList *nuevo;
 * nuevo = Queue_Pop(Q)...
 * Esta operacion recibe una Cola y retira de la misma
 * el elemento de mayor prioridad de acuerdo a la funcion f
 */
NodeList *queueDequeuePriority(Queue *St,cmpfn f);

/*
 * Funcion: QueuePeekFront
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * NodeList *nuevo;
 * nuevo = Queue_GetFront(Q);
 * Esta operacion recibe una Cola y retorna su elemento inicial(frente)
 */
NodeList *queuePeekFront(Queue *St);

/*
 * Funcion: queuePeekEnd
 * --------------------------
 * Modo de uso:
 * Queue *Q;
 * NodeList *nuevo;
 * nuevo = Queue_GetLast(Q);
 * Esta operacion recibe una Cola y retorna su elemento final
 */
NodeList *queuePeekEnd(Queue *Q);


int queueGetSize(Queue *Q);
#endif 
