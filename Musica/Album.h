#ifndef _ALBUM_H
#define _ALBUM_H

#include "../TDALib/list.h"

typedef struct Album
{
	char Nombre[50];
	char Artista[50];
	List *Lcanciones;
	int año;
}Album;

Album *AlbumNew(char nombre[50],char Artista[50],List *Lcanciones,int año);
void AlbumPrint(Album *A);
List *LlenarLAlbum(List *Lcanciones);
int BuscarAlbum(List *Al,char Nombre[50]);
void OrdenarListasAlbumes(List *L);
void AlbumPrintList(List *L);



#endif