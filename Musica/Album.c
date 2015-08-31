#include "Album.h"
#include "Cancion.h"


Album *AlbumNew(char nombre[50],char Artista[50],List *Lcanciones,int año)
{
	Album *A = NULL;
	A=(Album*)malloc(sizeof(Album));
	strcpy(A->Artista,Artista);
	strcpy(A->Nombre,nombre);
	A->Lcanciones = Lcanciones;
	A->año = año;

	return A;
}

void AlbumPrint(Album *A)
{
	NodeList *p = NULL;
	Cancion *C = NULL;
	int i = 0;
	
	printf("%s\t--\t%s",A->Nombre,A->Artista);

	for (p = A->Lcanciones->header; p != NULL; p = p->next)
	{
		i++;
		C=(Cancion*)nodeListGetCont(p);
		printf("%d.-\t%s\n",i,C->Nombre);
	}
}

List *LlenarLAlbum(List *Lcanciones)
{
	char n[50],a[50];
	int año = 0;
	NodeList *nod = NULL;
	Album *A = NULL;
	Cancion *C = NULL;
	List *Lalbum = NULL, *Lcan = NULL;
	FILE *f = NULL;

	f= fopen("Albumes.txt","r");
	Lalbum = listNew();

	while (!feof(f))
	{
		Lcan=listNew();
		fscanf(f,"%[^,],%d,%[^\n]\n",n,&año,a);

		for (nod = Lcanciones->header; nod != NULL; nod = nod->next)
		{
			C=(Cancion*)nodeListGetCont(nod);
			
			if(!strcmp(n,C->Album))
			{		 
				listAddNode(Lcan,nodeListNew(C));
			}
		}

		A=AlbumNew(n,a,Lcan,año);
		listAddNode(Lalbum,nodeListNew(A));

	}	
	fclose(f);

	return(Lalbum);
}
int BuscarAlbum(List *Al,char Nombre[50])
{
	NodeList *p = NULL;
	Album *A = NULL;

	for (p = Al->header; p != NULL; p = p->next)
	{
		A = (Album*)nodeListGetCont(p);

		if (strcmp(A->Nombre,Nombre)==0)
			return 1;
	}
	return 0;
}
void OrdenarListasAlbumes(List *L)
{
	NodeList *i = NULL, *j = NULL;
	Album *A1 = NULL, *A2 = NULL, *temp = NULL;

	for (i = L->header; i != NULL; i = i->next)
	{	
		A1 = (Album*)nodeListGetCont(i);

		for (j = L->header; j != NULL; j = j->next)
		{	
			A2 = (Album*)nodeListGetCont(j);
			if(A1->año > A2->año)
			{
				temp=(Album*)j->cont;
				j->cont = i->cont;
				i->cont = temp;
			}
		}
	}
}

void AlbumPrintList(List *L)
{
	NodeList *i = NULL;
	Album *A1 = NULL;

	A1=(Album*)nodeListGetCont(L->header);
	
	printf("\tLista de Albumes de %s\n\nAño\tNombre del Album",A1->Artista);
	
	for (i = L->header; i != NULL; i = i->next)
	{	
		A1=(Album*)nodeListGetCont(i);
		printf("\n%d\t%s",A1->año,A1->Nombre);	
	}
}