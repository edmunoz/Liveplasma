#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"

Libro* newLibro(char *titulo, char *autor, char *editorial, char *codigo, char *area, char *url){
	Libro* l = malloc(sizeof(Libro));
	strcpy(l->titulo, titulo);
	strcpy(l->autor, autor);
	strcpy(l->editorial, editorial);
	strcpy(l->codigoISBN, codigo);
	l->ranking = 0;
	strcpy(l->area, area);
	strcpy(l->url, url);
	return l;
}

List* llenarLibro(){
	char titulo[100];
	char autor[50];		//Identificación del autor del libro
	char editorial[50];
	char codigoISBN[50];
	char area[50];
	char url[50];

	NodeList *nl = NULL;	
	Libro* libro = NULL;
	List* libros = NULL;
	FILE *f = NULL;
	int x = 0;

	f = fopen("Libros.txt", "r");
	libros = listNew();
	while (!feof(f)){
		x = fscanf(f, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", titulo, autor, editorial, codigoISBN, area, url);
		if (x>0){
			libro = newLibro(titulo, autor, editorial, codigoISBN, area, url);
			nl = nodeListNew(libro);
			listAddNode(libros, nl);
		}
	}
	listPrint(libros, printLibro);

	fclose(f);

	return(libro);
}

void printLibro(Libro* libro){
	printf("Titulo: %s \n", libro->titulo);
	printf("Autor: %s \n", libro->titulo);
	printf("Editorial: %s \n", libro->titulo);
	printf("Codigo ISBN: %s \n", libro->titulo);
	printf("Area: %s \n", libro->titulo);
	printf("Acceso url: %s \n", libro->titulo);
}