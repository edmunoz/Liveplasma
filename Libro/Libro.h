#ifndef _LIBRO_H
#define _LIBRO_H

#include "../TDALib/list.h"

typedef struct TLibro
{
	char titulo[100];
	char autor[50];		//Identificación del autor del libro
	char editorial[50];	
	char codigoISBN[50];
	int ranking;
	char area[50];
	char url[50];
}Libro;

/**
* Funcion que permite crear un nuevo libro.
* @fecha 30 08 2015
* @param titulo Titulo del libor
* @param autor Autor del libro
* @param editorial Editorial del libro
* @param codigo Codigo ISBN del libro
* @return Libro
*/
Libro *newLibro(char *titulo, char *autor, char *editorial,char *codigo,char *area,char *url);

List* llenarLibro();

void printLibro(Libro* libro);

#endif