#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autor.h"

Autor* newAutor(char *autor){
	Autor* a = (Autor*)malloc(sizeof(Autor));
	strcpy(a->autor, autor);
	a->ranking = 0;
	a->libros = listNew();
	return a;
}

List *lenarAutores(){
	List *autores = NULL;
	FILE *f = NULL;
	NodeList *nl = NULL;
	Autor *autor = NULL;
	char a[50];
	int x = 0;
	f = fopen("Autores.txt", "r");
	autores = listNew();
	while (!feof(f)){
		x = fscanf(f, "%[^\n]\n",a);
		if (x>0)
			listAddNode(autores, nodeListNew(newAutor(a)));
	}
	//listPrint(autores, printAutores);
	fclose(f);
	return(autores);
}

void printAutores(Autor* autor){
	printf("Autor: %s \n",autor->autor);
}