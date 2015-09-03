#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autor.h"

Autor *newAutor(char *nombre)
{
	Autor *a = malloc(sizeof(Autor));
	strcpy(a->nombre, nombre);
	return a;
}