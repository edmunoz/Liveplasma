#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autor.h"
#include "Libro.h"

Autor* newAutor(char *autor,List *libros){
	Autor* a = (Autor*)malloc(sizeof(Autor));
	strcpy(a->autor, autor);
	a->ranking = 0;
	a->libros = libros;
	return a;
}

List *lenarAutores(List* libros){
	FILE *f = NULL;
	NodeList *iterator = NULL;
	Autor *autor = NULL;
	Libro *libro = NULL;
	List *librosPorAutor;
	List *autores;
	char a[50];
	int x = 0;
	f = fopen("Autores.txt", "r");
	autores = listNew();
	while (!feof(f)){
		librosPorAutor = listNew();
		x = fscanf(f, "%[^\n]\n",a);		
		for (iterator = libros->header; iterator != NULL; iterator = iterator->next){
			libro = (Libro*)nodeListGetCont(iterator);
			if (!strcmp(a, libro->autor)){
				listAddNode(librosPorAutor, nodeListNew(libro));
			}
		}
		autor = newAutor(a, librosPorAutor);
		listAddNode(autores, autor);
	}
	//listPrint(autores, printAutores);
	fclose(f);
	return(autores);
}

void printAutores(Autor* autor){
	printf("Autor: %s \n",autor->autor);
}