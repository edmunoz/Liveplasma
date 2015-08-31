#include "stack.h"
#include "list.h"
/*
 * ARCHIVO:
 *      stack.c
 * 		�ltima modificaci�n: 2007/03/27 (V. Mac�as)
 * --------------------------------------------------------------------------------------
 * DESCRIPCION:
 * 		Este archivo contiene la implementacion de las operaciones
 *		para el manejo del TDA Stack (Pila)
 *
 * DEPENDENCIAS:
 *      stack.h:   la interfaz
 * MODIFICACIONES:
 *		2004/06/08 (Marisol Villacres):	Version original 
 *		2007/03/27 (V. Mac�as):	Version con nombres en ingl�s.
 */

int stackIsEmpty(Stack *S){
	return listIsEmpty(S);
}

Stack* stackNew(){
	Stack *S;
	S = listNew();
	return S;
}

void stackPush(Stack *S, NodeList *nuevo){
	listAddNode(S, nuevo);
}

NodeList *stackPop(Stack *S){
	return(listRemoveLast(S));
}

NodeList *stackPeek(Stack *S){
	return listGetLast(S);
}

int stackGetSize(Stack *S){
	return listGetSize(S);
}
