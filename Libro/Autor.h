#ifndef _AUTOR_H
#define _AUTOR_H

#include "../TDALib/list.h"

typedef struct Autor
{
	char nombre[50];
	List *libros;

}Autor;


/**
* Funcion que permite crear un nuevo autor.
* @fecha 30 08 2015
* @param nombre Nombre del autor
* @return Autor
*/
Autor *newAutor(char *nombre);



#endif