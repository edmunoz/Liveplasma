#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"

Libro* newLibro(char *titulo, char *autor, char *editorial, char *codigo,int anio){
	Libro* l = malloc(sizeof(Libro));
	strcpy(l->titulo, titulo);
	strcpy(l->autor, autor);
	strcpy(l->editorial, editorial);
	strcpy(l->codigoISBN, codigo);
	l->ranking = 0;
	l->anio = anio;
	return l;
}

List* llenarLibro(List *autores){

	char titulo[50];
	char autor[50];		//Identificación del autor del libro
	char editorial[50];
	char codigoISBN[50];
	char area;

	NodeList *nl = NULL;
	Libro* libro = NULL;
	FILE *f = NULL;

	f = fopen("Libros.txt", "r");
	libro = listNew();

	while (!feof(f))
	{
		fscanf(f, "%[^];%[^];%[^];%[^];%[^\n]\n",titulo,autor,editorial,codigoISBN,area);

	}
	fclose(f);

	return(libro);
}