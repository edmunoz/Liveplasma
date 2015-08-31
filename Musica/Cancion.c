#include "..\Musica\Cancion.h"


Cancion *CancionNew(char nombre[50],char URL[100],char Album[50],char Artista[50],char genero[50])
{
	Cancion *C = NULL;
	C = (Cancion*)malloc(sizeof(Cancion));

	strcpy(C->Nombre,nombre);
	strcpy(C->URL,URL);
	strcpy(C->Album,Album);
	strcpy(C->Artista,Artista);
	strcpy(C->Genero,genero);
	C->Ranking=0;

	return C;
}

void CancionPrint(Cancion *C)
{
	printf("%s\t--\t%s\t--\t%s",C->Nombre,C->Album,C->Artista);
}

List *LlenarLCanciones()
{
	List *Lcanciones = NULL;
	FILE *f = NULL;
	NodeList *p = NULL;
	Cancion *C = NULL;
	char n[50], al[50], ar[50], ge[50], URL[100];
	int x = 0;

	f= fopen("Canciones.txt","r");
	Lcanciones = listNew();

	while (!feof(f))
	{
		x = fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ar,al,n,ge,URL);
	
		if(x>0)
			listAddNode(Lcanciones,nodeListNew(CancionNew(n,URL,al,ar,ge)));


	}
	fclose(f);

	return(Lcanciones);

}
int BuscarCancion(List *Al,char Nombre[50])
{
	NodeList *p = NULL;
	Cancion *C = NULL;
	for (p = Al->header; p != NULL; p = p->next)
	{
		C = (Cancion*)nodeListGetCont(p);

		if (strcmp(C->Nombre,Nombre) == 0)
			return 1;
	}
	return 0;
}

void OrdenarListasCanciones(List *L)
{
	NodeList *i = NULL,*j = NULL;
	Cancion *C1 = NULL, *C2 = NULL, *temp = NULL;

	for (i = L->header; i != NULL; i = i->next)
	{	
		C1 = (Cancion*)nodeListGetCont(i);

		for (j = L->header; j != NULL; j = j->next)
		{	
			C2 = (Cancion*)nodeListGetCont(j);

			if(C1->Ranking > C2->Ranking)
			{
				temp = (Cancion*)j->cont;
				j->cont = i->cont;
				i->cont = temp;
			}
		}
	}
}

List *ListasCancionesTOP(List *L)
{
	NodeList *i = NULL, *j = NULL;
	Cancion *C1 = NULL, *C2 = NULL, *temp = NULL;
	List *Lista = NULL;
	int cont = 0;

	Lista = listNew();
	
	for (i = L->header; i != NULL && cont != 10; i = i->next)
	{	
		cont ++;
		C1 = (Cancion*)nodeListGetCont(i);
		listAddNode(Lista, nodeListNew(C1));
	}
	return Lista;
}

void ListPrintCanTOP(List *ListaCanciones)
{
	NodeList *i = NULL;
	Cancion *C = NULL;
	int cont = 1;
	
	printf("TOP 10 DE CANCIONES\nELECTRONICA\n");

	for (i = ListaCanciones->header; i != NULL; i = i->next)
	{
		C=(Cancion*)nodeListGetCont(i);

		if(strcmp(C->Genero,"Electronica") == 0 && C->Ranking > 0)
		{
			printf("%d %s %s\n",cont,C->Artista,C->Nombre);
			cont ++;
		}
	}
	cont=1;
	
	printf("\nPOP\n");

	for (i = ListaCanciones->header; i != NULL; i = i->next)
	{
		C = (Cancion*)nodeListGetCont(i);

		if(strcmp(C->Genero,"Pop") == 0 && C->Ranking > 0)
		{
			printf("%d %s %s\n",cont,C->Artista,C->Nombre);
			cont ++;
		}
	}

	cont=1;
	printf("\nREGGAETON\n");
	
	for (i = ListaCanciones->header; i != NULL; i = i->next)
	{
		C = (Cancion*)nodeListGetCont(i);
		if( strcmp(C->Genero,"Reggaeton") == 0 && C->Ranking>0 )
		{
			printf("%d %s %s\n",cont,C->Artista,C->Nombre);
			cont ++;
		}
	}

	cont=1;
	
	printf("\nROCK\n");
	
	for (i = ListaCanciones->header; i != NULL; i = i->next)
	{
		C = (Cancion*)nodeListGetCont(i);
		if(strcmp(C->Genero,"Rock") == 0 && C->Ranking > 0)
		{
			printf("%d %s %s\n", cont, C->Artista, C->Nombre);
			cont ++;
		}
	}

	cont=1;
	printf("\nSALSA\n");
	
	for (i = ListaCanciones->header; i != NULL; i = i->next)
	{
		C = (Cancion*)nodeListGetCont(i);
		if(strcmp(C->Genero,"Salsa") == 0 && C->Ranking>0)
		{
			printf("%d %s %s\n", cont, C->Artista, C->Nombre);
			cont ++;
		}
	}
}
