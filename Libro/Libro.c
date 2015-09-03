#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"


Libro *newLibro(char *titulo, char *autor, char *editorial, char *codigo)
{
	Libro *l = malloc(sizeof(Libro));
	strcpy(l->titulo, titulo);
	strcpy(l->autor, autor);
	strcpy(l->editorial, editorial);
	strcpy(l->codigoISBN, codigo);

	return l;
}