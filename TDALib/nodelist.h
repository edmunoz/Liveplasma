
#ifndef _NODE_H
#define	_NODE_H
#include "..\TDALib\generic.h"

typedef struct NodeList{
    Generic cont;
    struct NodeList *next;
}NodeList;

NodeList *nodeListNew(Generic g);
void nodeListSetCont(NodeList *p, Generic g);
Generic nodeListGetCont(NodeList *p);
void nodeListSetNext(NodeList *p, NodeList *q);
NodeList *nodeListGetNext(NodeList *p);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _NODE_H */

