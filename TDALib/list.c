
#include "list.h"
#include <stdlib.h>

List *listNew(){
    List *newList = (List*)malloc(sizeof(List));
    newList->header = newList->last = NULL;
    return newList;
}
int listIsEmpty(List *L){
    return (L->header == NULL && L->last == NULL);
}
NodeList *listGetHeader(List *L){ return L->header; }

NodeList *listGetLast(List *L) { return L->last; }

void listAddNode(List *L, NodeList *newNode){
    nodeListSetNext(newNode, NULL);
    if(listIsEmpty(L))
        L->header = L->last = newNode;
    else {
        nodeListSetNext(L->last, newNode);
        L->last = newNode;
    }
}

void listAddFirst(List *L, NodeList *newNode){
    if(listIsEmpty(L)){
        L->header = L->last = newNode;
    }else{
        newNode->next = L->header;
        L->header = newNode;
    }
}
NodeList * listSearch(List *L, Generic value, cmpfn cmp){
    NodeList *iterator;
    for(iterator = L->header; iterator!=NULL; iterator = iterator->next){
        if(cmp(iterator->cont, value) == 0) return iterator;
    }
    return NULL;
}
NodeList * listGetPrevious(List *L, NodeList *p){
    NodeList *iterator;
    for(iterator = L->header; iterator->next!=NULL; iterator = iterator->next ){
        if(iterator->next == p) return iterator;
    }
    return NULL;

}
int listNodeExists(List *L, NodeList *p){
    NodeList *iterator;
    for(iterator = L->header; iterator!=NULL; iterator = iterator->next ){
        if(iterator == p) return 1;
    }
    return 0;
}


void listAddNext(List *L, NodeList *p, NodeList *newNode){
    if(!listNodeExists(L, p)) return;
    else if(p == L->last) listAddNode(L, newNode);
    else{
        newNode->next = p->next;
        p->next = newNode;
    }
}

void listRemoveNode(List *L, NodeList *p){
    if(!listNodeExists(L, p)) return ;
    if(p == L->last) listRemoveLast(L);
    else if(p == L->header) listRemoveFirst(L);
    else{
        NodeList *ant = listGetPrevious(L, p);
        ant->next = p->next;
        p->next = NULL;
        }
    return;
} 

NodeList *listRemoveFirst(List *L){
    NodeList *tmp;
    if(listIsEmpty(L)) return NULL;
    tmp = L->header;
    if(L->header == L->last) L->last = NULL;
    L->header = L->header->next;
    tmp->next = NULL;
    return tmp;
}

NodeList *listRemoveLast(List *L){
    NodeList *tmp;
    if(listIsEmpty(L)) return NULL;
    tmp = L->last;
    if(L->header == L->last) L->header = L->last = NULL;
    else{
        NodeList *ant = listGetPrevious(L, L->last);
        L->last = ant;
        ant->next = NULL;
    }
    return tmp;
}

int listGetSize(List *L){
    int cont = 0;
    NodeList *iterator;
    for(iterator = L->header; iterator!=NULL; iterator = iterator->next)
        cont++;
    return cont;
}
void listDelete(List **L){
    free(*L);
}

void listPrint(List *L, printfn print){
    NodeList *iterator; int i = 0;    
    for(iterator = L->header; iterator!=NULL; iterator = iterator->next)
        print(iterator->cont);
    
}

List *listReadFile(char *fileName, readfn readLine){
    List *L = listNew();
    FILE *F = fopen(fileName, "r");
    if (F==NULL)	
	return(NULL);
    while(!feof(F)){
        Generic g;
        g = readLine(F);
        if(!feof(F))
            listAddNode(L, nodeListNew(g));
    }
    return L;
}











