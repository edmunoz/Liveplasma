#include <stdlib.h>
#include "graph.h"



Graph *graphNew()
{
	return listNew();
}

void graphDelete(Graph **G)
{
	listDelete(G);
}

GVertex *gVertexNew(Generic content)
{
	GVertex *v =(GVertex *)malloc(sizeof(GVertex));

	if(v)
	{
		v->content = content;
		v->visited = 0;
		v->LAdjacents = listNew();
	}
	return v;
}

void gVertexDelete(GVertex **v)
{
	free((*v)->content);
	listDelete(&((*v)->LAdjacents));
	free(&v);
}

Generic gVertexGetContent(GVertex *v)
{
	Generic content = NULL;
	if(v)
	{
		content = v->content;
	}
	return content;
}

List *gVertexGetAdjacents(GVertex *v)
{
	return(v->LAdjacents);
}

int gVertexIsVisited(GVertex *v){
	return(v->visited);
}

Generic gEdgeGetExtraInfo(GEdge *e){
	return(e->ExtraInfo);
}

int gEdgeGetWeight(GEdge *e){
	return(e->weight);
}

GVertex *gEdgeGetSource(GEdge *e){
	return(e->source);
}

GVertex *gEdgeGetDestination(GEdge *e){
	return(e->destination);
}

void gVertexVisit(GVertex *v)
{
	v->visited = 1;
}
void gVertexClearVisit(GVertex *v){
	v->visited = 0;    
}

void graphAddVertex(Graph *G, GVertex *v)
{
	NodeList *pNode=NULL;
	
	pNode = nodeListNew(v);
	if(pNode)
	{
		listAddNode(G, pNode);
	}
}

NodeList *graphRemoveVertex(Graph *G, GVertex *V, cmpfn cmp)
{
	NodeList *pnodovertice;
//	listDelete(&V->LAdjacents);
	for(pnodovertice = listGetHeader(G); pnodovertice!=NULL; 
			pnodovertice = nodeListGetNext(pnodovertice)){
				graphUnlinkVertices(G, (GVertex*)nodeListGetCont(pnodovertice), V); 		
	}
	pnodovertice = listSearch(G, V, cmp);
	listRemoveNode(G, pnodovertice);
	return pnodovertice;
}

void graphLinkVertices(Graph *G, GVertex *source, GVertex *destination, int weight, Generic ExtraInfo)
{
	GEdge *a=NULL;
	NodeList *pNodo=NULL;

	a = (GEdge *)malloc(sizeof(GEdge));
	if(a)
	{
		a->source = source;
		a->destination = destination;
		a->weight = weight;
                a->ExtraInfo = ExtraInfo;

		pNodo=nodeListNew(a);
		if(pNodo)
		{
			listAddNode(source->LAdjacents, pNodo);
		}
		else
		{
			free(a);
			a = NULL;
		}
	}
}

void graphUnlinkVertices(Graph *G, GVertex *source, GVertex *destination)
{
	NodeList *pnodo_arco;
	if(!source->LAdjacents) return;
	pnodo_arco = listSearch(source->LAdjacents, destination,gEdgeCmpxDestination);
	if(pnodo_arco){
		listRemoveNode(source->LAdjacents, pnodo_arco);
//		free(pnodo_arco->cont);
		//nodeListDelete(&pnodo_arco);
	}
}

int graphIsEmpty(Graph *G)
{
	return listIsEmpty(G);
}

GEdge *graphGetLink(GVertex *source, GVertex *destination)
{
	NodeList *p;

	if (!source->LAdjacents || listIsEmpty(source->LAdjacents)) return(NULL);

	p = listSearch(source->LAdjacents,destination,gEdgeCmpxDestination);
	if (!p) return(NULL);

	return((GEdge*)nodeListGetCont(p));
}

int gEdgeCmpxDestination(GEdge *e, GVertex *destination)
{
	if(e->destination == destination)
		return(0);
	return(1);
}

int graphCountVertices(Graph *G){
	return listGetSize(G);
}

int graphCountEdges(Graph *G){
	int total=0;
	GVertex *cvert;
	NodeList *p;
	for(p = listGetHeader(G); p!=NULL; p = nodeListGetNext(p)){
		cvert = (GVertex*)nodeListGetCont(p);
		total += listGetSize(cvert->LAdjacents);
	}
	return total;
}

int GVertexCompare(GVertex *V1, GVertex *V2)
{
	if(V1==V2)
		return(0);
	return(1);
}

GVertex *graphSearchVertex(Graph *G, Generic cont, cmpfn cmp){
	GVertex *v;
	NodeList *p;
	for(p = listGetHeader(G); p!=NULL; p = nodeListGetNext(p)){
		v = (GVertex*)nodeListGetCont(p);
		if(cmp(v->content, cont) == 0) return v;
	}
	return NULL;
}

void graphInit(Graph *G){
	GVertex *v;
	NodeList *p;

	for(p=listGetHeader(G);p!=NULL;p=nodeListGetNext(p)){
		v = (GVertex*)nodeListGetCont(p);
		gVertexClearVisit(v);
	}
}

void graphPrint(Graph *G, printfn prVertex, printfn prEdge){
    NodeList *p,*q;
	GVertex *vdestination,*vsource;
    for(p = listGetHeader(G); p!= NULL; p = nodeListGetNext(p)){
		GVertex *v = (GVertex *)nodeListGetCont(p);
        for(q = listGetHeader(v->LAdjacents); q!= NULL; q = nodeListGetNext(q)){
			GEdge *e = (GEdge *)nodeListGetCont(q);
            vsource = e->source;
            prVertex(vsource->content);
            printf(" --- [%d] ", e->weight);
            vdestination = e->destination;
            if(prEdge) prEdge(e->ExtraInfo);
            printf("---> ");
            prVertex(vdestination->content);     
            printf("\n");
        }
    }
}
