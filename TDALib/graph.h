#ifndef _GRAPH_H_
#define _GRAPH_H_

/*
 * ARCHIVO:
 *      graph.h
 * --------------------------------------------------------------------------------------
 * DESCRIPCION:
 * 		Este archivo contiene la interfaz del TDA GRAPH
							TDA GRAPH

	GRAPH: Lista de vertices (TDA Vertex)
	+-----------+---------+   +-----------+---------+   +-----------+---------+   
	| content   |  next  -+-->| content   |  next  -+-->| content   |  next  -+--+
	+-----+-----+---------+   +-----------+---------+   +-----------+---------+  |
	      |																		===
 +--------+
 |	TDA Vertex
 |	+------------+
 +->    |  content   | --> Informacion encapsulada en el vertice
	+------------+
	|  visited   | --> Bandera para algoritmos de recorridos
	+------------+
	| LAdjacents |
	+-----+------+
	      |		
 +--------+
 |	
 |	Lista de Arcos (TDA Edge) adyacentes
 |	+-----------+---------+   +-----------+---------+   +-----------+---------+   
 +->    |   content  |  next -+-->|   content  |  next -+-->|   content  |  next -+--+
	+-----+-----+---------+   +-----------+---------+   +-----------+---------+  |
		  |																		===
 +--------+
 |  TDA Edge
 |  +------------+
 +->|	source   | --> Vertice Origen
    +------------+
    |destination | --> Vertice Destion
    +------------+
    |	weight   | --> Factor de peso
    +------------+
    | ExtraInfo  | --> Informacion adicional que se puede guardar en el arco
    +------------+
*/

#include "nodelist.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

#define MAX_DIST 66000


//Grafo dirigido solamente
typedef List Graph;
typedef struct GVertex
{
	Generic content;List *LAdjacents;int visited;
}GVertex;
typedef struct GEdge	
{
	int	weight;	Generic ExtraInfo; GVertex *source;GVertex *destination;
}GEdge;
Graph *graphNew();
void graphDelete(Graph **G);
GVertex *gVertexNew(Generic content);
void gVertexDelete(GVertex **V);
Generic gVertexGetContent(GVertex *v);
List *gVertexGetAdjacents(GVertex *v);
int gVertexIsVisited(GVertex *v);
Generic gEdgeGetExtraInfo(GEdge *e);
int gEdgeGetWeight(GEdge *e);
GVertex *gEdgeGetSource(GEdge *e);
GVertex *gEdgeGetDestination(GEdge *e);
void gVertexVisit(GVertex *v);
void gVertexClearVisit(GVertex *v);
void graphAddVertex(Graph *G, GVertex *v);
NodeList *graphRemoveVertex(Graph *G, GVertex *V, cmpfn fn);
void graphLinkVertices(Graph *G, GVertex *vsource, GVertex *vdestination, int weight, Generic extraInfo);
void graphUnlinkVertices(Graph *G, GVertex *vsource, GVertex *vdestination);
int graphisEmpty(Graph *G);
GEdge *graphGetLink(GVertex *vsource, GVertex *vdestination);
int gEdgeCmpxDestination(GEdge *e, GVertex *vdestination);
int graphCountVertices(Graph *G);
int graphCountEdges(Graph *G);
int gVertexCompare(GVertex *v, GVertex *ov);
GVertex *graphSearchVertex(Graph *G, Generic cont, cmpfn fn);
void graphInit(Graph *G);
void graphPrint(Graph *G, printfn prVertex, printfn prEdge);

/** @} */
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
#endif
