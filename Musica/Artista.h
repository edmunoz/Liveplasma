#ifndef _ARTISTA_H
#define _ARTISTA_H
#include "Album.h"

#include "../TDALib/list.h"
#include "../TDALib/graph.h"

typedef struct Artista
{
	char Nombre[50];
	List *Lalbumes;
	char genero[50];
	int ranking;
}Artista;

Artista* ArtistaNew(char nombre[50], List *Lalbumes, char gen[50]);
void ArtistaPrint(Artista *Ar);
Graph* LlenarGraphArtistas(List *Lalbum);
void ListaArtistasPrint(Graph *Ar);
int BuscaArtista(Graph *Ar,char Nombre[50]);
List *ListAlbumArtista(Graph *Artistas,char NombreArtista[50]);
List *ListCancionesAlbumPrint(List *Al,char NombreAlbum[50]);
void ActualizarGrafo(Graph *Artistas,char NombreCancion[50], char NombreAlbum[50],char url[200]);
Graph* ListArtistasRelacionados(Graph *Artistas,char NombreArtista[50]);
List* ListCanciones(Graph *Artistas);
List* ListArtistas(Graph *Artistas);
void OrdenarListasArtistas(List *L);
void ListPrintArtTOP(List *ListaCanciones);
List* ListasArtistasTOP(List *L);


#endif