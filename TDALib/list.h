#ifndef _LIST_H
#define	_LIST_H



#include "..\TDALib\nodelist.h"


typedef struct List{
    NodeList *header, *last;
}List;


List *listNew();
int listIsEmpty(List *L);
NodeList *listGetHeader(List *L);
NodeList *listGetLast(List *L);
void listAddNode(List *L, NodeList *newNode);
void listAddFirst(List *L, NodeList *newNode);
void listAddNext(List *L, NodeList *p, NodeList *newNode);
NodeList *listSearch(List *L, Generic value,cmpfn f);                                                                                                                                                                                                                                                                                                                                                                         
NodeList *listGetPrevious(List *L, NodeList *p);
void listRemoveNode(List *L, NodeList *p);
NodeList *listRemoveFirst(List *L);
NodeList *listRemoveLast(List *L);
int listNodeExists(List *L, NodeList *p);
int listGetSize(List *L);
void listDelete(List **L);
void listPrint(List *L, printfn print);
List *listReadFile(char *fileName, readfn read);

/** @} */
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _LIST_H */

