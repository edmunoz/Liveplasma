#include "nodelist.h"
#include <stdlib.h>

NodeList *nodeListNew(Generic g){
    NodeList *newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->next = NULL;
    newNode->cont = g;
    return newNode;
}
void nodeListSetCont(NodeList *p, Generic g){
    p->cont = g;
}
Generic nodeListGetCont(NodeList *p){
    return p->cont;
}
void nodeListSetNext(NodeList *p, NodeList *q){
    p->next = q;
}
NodeList *nodeListGetNext(NodeList *p){
    return p->next;
}
