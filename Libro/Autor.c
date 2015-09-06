#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autor.h"

Autor* newAutor(char *nombre){
	Autor* a = (Autor*)malloc(sizeof(Autor));
	strcpy(a->nombre, nombre);
	a->ranking = 0;
	a->libros = listNew();
	return a;
}