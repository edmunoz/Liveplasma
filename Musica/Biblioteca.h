/*
PROYECTO: BIBLIOTECA DE MUSICA

AUTORES:
- ANDRADE WIESNER KATHERINE DANIELA
- GONZALEZ CHIRIBOGA CINTHYA VANESSA
- LITARDO SANDOVAL GISELL ESTHER
- PE�AFIEL PE�AFIEL CRISTINA ELIZABETH
*/
#ifndef _BIBLIOTECA_H
#define _BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "../TDALib/list.h"
#include "../TDALib/graph.h"
#include "../Musica/Cancion.h"
#include "../Musica/Album.h"
#include "../Musica/Artista.h"

#include "../Musica/Libro.h"
#include "../Musica/Autor.h"


void menuMusica();
void menuLibro();
void busquedaNombreArtista(int *op1, Graph *Artistas, Graph *LartistasRelacionados, List *Lalbum, List *Lcancion);
void topCanciones(Graph *Artistas, List *Lcancion, List *LcancionesTOP);
void topArtistas(Graph *Artistas, List *Lartistas, List *LartistasTOP);

#endif