#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autor.h"

Autor *newLibro(char *nombre)
{
	Autor *a = malloc(sizeof(Autor));
	strcpy(a->nombre, nombre);

	return a;
}