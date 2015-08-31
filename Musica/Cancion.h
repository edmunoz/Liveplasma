#ifndef _CANCION_H
#define _CANCION_H
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include "../TDALib/list.h"
#include "../TDALib/graph.h"

typedef struct Cancion
{
	char Nombre[50];
	int Ranking;
	char URL[100];
	char Album[50];
	char Artista[50];
	char Genero[50];
}Cancion;

Cancion *CancionNew(char nombre[50],char URL[100],char Album[50],char Artista[50],char Genero[50]);
void CancionPrint(Cancion *C);
List *LlenarLCanciones();
int BuscarCancion(List *Al,char Nombre[50]);
void OrdenarListasCanciones(List *L);
void ListPrintCanTOP(List *ListaCanciones);
List *ListasCancionesTOP(List *L);

#endif