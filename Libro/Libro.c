#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"

Libro* newLibro(char *titulo, char *autor, char *editorial, char *codigo){
	Libro* l = malloc(sizeof(Libro));
	strcpy(l->titutlo, titulo);
	strcpy(l->autor, autor);
	strcpy(l->editorial, editorial);
	strcpy(l->codigoISBN, codigo);
	l->ranking = 0;
	return l;
}