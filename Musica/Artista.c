#include "Artista.h"

Artista *ArtistaNew(char nombre[50],List *Lalbum,char gen[50])
{
	Artista *Ar = NULL;
	Ar=(Artista*)malloc(sizeof(Artista));
	Ar->Lalbumes=Lalbum;
	strcpy(Ar->Nombre,nombre);
	strcpy(Ar->genero,gen);
	Ar->ranking=0;
	return Ar;
}

void ArtistaPrint(Artista *Ar)
{
	NodeList *p = NULL, *q = NULL;
	Album *Al = NULL;
	Cancion *C = NULL;
	
	printf("\t--\t%s\t--\t\n",Ar->Nombre);

	for (p = Ar->Lalbumes->header; p != NULL; p = p->next)
	{
		Al=(Album *)nodeListGetCont(p);

		for (q = Al->Lcanciones->header; q != NULL; q = q->next)
		{
			C=(Cancion *)nodeListGetCont(q);
			printf("%s",C->Nombre);
		}
	}
}

void ListaArtistasPrint(Graph *Ar)
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL;
	Artista *Art = NULL;
	
	for (i = Ar->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		printf("%s\n",Art->Nombre);
	}
}

int BuscaArtista(Graph *Ar,char Nombre[50])
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL;
	Artista *Art = NULL;

	for (i = Ar->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		
		if (strcmp(Art->Nombre,Nombre)==0)
			return 1;
	}
	return 0;
}

Graph *LlenarGraphArtistas(List *Lalbum)
{
	char n[50], gen[50];
	NodeList *nod = NULL, *p = NULL, *q = NULL;
	Artista *Ar = NULL, *Ar1 = NULL;
	Album *Al = NULL;
	Cancion *C = NULL;
	GVertex *V = NULL, *V1 = NULL;
	Graph *GArtistas = NULL, *Lal = NULL;
	FILE *f = NULL;

	GArtistas = graphNew();
	f= fopen("Artistas.txt","r");

	while (!feof(f))
	{
		Lal=listNew();
		fscanf(f,"%[^,],%[^\n]\n",n,gen);

		for (nod = Lalbum->header; nod != NULL; nod = nod->next)
		{
			Al=(Album*)nodeListGetCont(nod);
			
			if(!strcmp(n,Al->Artista))
			{		 
				listAddNode(Lal,nodeListNew(Al));
			}
		}
		
		//printf("%s\n",n);
		Ar=ArtistaNew(n,Lal,gen);
		V=gVertexNew(Ar);
		graphAddVertex(GArtistas,V);

	}	
	
	fclose(f);

	for (p = GArtistas->header; p != NULL; p = p->next)
	{
		V=(GVertex*)nodeListGetCont(p);
		Ar=(Artista*)gVertexGetContent(V);

		for (q = GArtistas->header; q != NULL; q = q->next)
		{
			V1=(GVertex*)nodeListGetCont(q);
			Ar1=(Artista*)gVertexGetContent(V1);

			if ((strcmp(Ar->Nombre,Ar1->Nombre)!=0)&&strcmp(Ar->genero,Ar1->genero)==0)
			{
				listAddNode(V->LAdjacents,nodeListNew(V1));
				graphLinkVertices(GArtistas,V,V1,0,NULL);
				graphLinkVertices(GArtistas,V1,V,0,NULL);
			}
		}
	}
	return(GArtistas);
}

List *ListAlbumArtista(Graph *Artistas,char NombreArtista[50])
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL, *j = NULL;
	Artista *Art = NULL;
	Album *Al = NULL;
	List *Lalbum = NULL;

	Lalbum=listNew();

	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);

		if (strcmp(Art->Nombre,NombreArtista)==0)
		{
			for (j = Art->Lalbumes->header; j != NULL; j = j->next)
			{
				Al=(Album*)nodeListGetCont(j);
				listAddNode(Lalbum,nodeListNew(Al));
			}
		}

	}
	return Lalbum;
}
List *ListCanciones(Graph *Artistas)
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL, *j = NULL, *k = NULL;
	Artista *Art = NULL;
	Album *Al = NULL;
	Cancion *C = NULL;
	List *Lcanciones = NULL;
	
	Lcanciones=listNew();

	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);

		for (j = Art->Lalbumes->header; j != NULL; j = j->next)
		{
			Al=(Album*)nodeListGetCont(j);
			for (k = Al->Lcanciones->header; k != NULL; k = k->next)
			{
				C=(Cancion*)nodeListGetCont(k);
				listAddNode(Lcanciones,nodeListNew(C));
			}
		}

	}
	return Lcanciones;
}

List *ListCancionesAlbumPrint(List *Al,char NombreAlbum[50])
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL, *j = NULL;
	Artista *Art = NULL;
	Album *A = NULL;
	Cancion *C = NULL;
	List *Lcanciones = NULL;

	Lcanciones=listNew();
	
	for (i = Al->header; i != NULL; i = i->next)
	{
		A=(Album*)nodeListGetCont(i);
		if (strcmp(A->Nombre,NombreAlbum)==0)
		{
			for (j = A->Lcanciones->header; j != NULL; j = j->next)
			{
				C=(Cancion*)nodeListGetCont(j);
				printf("%s\n",C->Nombre);
				listAddNode(Lcanciones,nodeListNew(C));
			}
		}

	}
	return Lcanciones;
}

Graph *ListArtistasRelacionados(Graph *Artistas,char NombreArtista[50])
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL, *j = NULL;
	Artista *Art = NULL;
	Album *Al = NULL;
	Graph *LArtistasRelacionados = NULL;
	char gen[50];
	
	LArtistasRelacionados=graphNew();
	
	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		if (strcmp(Art->Nombre,NombreArtista)==0)
			strcpy(gen,Art->genero);
	}

	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		if ((strcmp(Art->Nombre,NombreArtista)!=0)&&(strcmp(gen,Art->genero)==0))
			graphAddVertex(LArtistasRelacionados,Art1);
	}
	return LArtistasRelacionados;
}

List *ListArtistas(Graph *Artistas)
{
	GVertex *Art1 = NULL;
	NodeList *i = NULL;
	Artista *Art = NULL;
	List *LArtistas = NULL;

	LArtistas=listNew();
	
	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		listAddNode(LArtistas,nodeListNew(Art));
	}
	return LArtistas;
}

void OrdenarListasArtistas(List *L)
{
	NodeList *i,*j;
	Artista *A1,*A2,*temp;

	for (i = L->header; i != NULL; i = i->next)
	{	
		A1=(Artista*)nodeListGetCont(i);
		for (j = L->header; j != NULL; j = j->next)
		{	
			A2=(Artista*)nodeListGetCont(j);
			if(A1->ranking>A2->ranking)
			{
				temp=(Artista*)j->cont;
				j->cont=i->cont;
				i->cont=temp;
			}
		}
	}
}

void ActualizarGrafo(Graph *Artistas,char NombreCancion[50], char NombreAlbum[50],char url[200])
{
	GVertex *Art1;
	NodeList *i,*j,*k;
	Artista *Art;
	Album *Al;
	List *Lalbum;
	Cancion *C;
	char NombreArtista[50];
	Lalbum=listNew();
	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		for (j = Art->Lalbumes->header; j != NULL; j = j->next)
		{
			Al=(Album*)nodeListGetCont(j);
			for (k = Al->Lcanciones->header; k != NULL; k = k->next)
			{
				C=(Cancion*)nodeListGetCont(k);
				if ((strcmp(C->Nombre,NombreCancion)==0)&&(strcmp(C->Album,NombreAlbum)==0))
				{
					strcat(url,C->URL);
					C->Ranking ++;
					strcpy(NombreArtista,C->Artista);
				}
			}
		}
	}
	for (i = Artistas->header; i != NULL; i = i->next)
	{
		Art1=(GVertex*)nodeListGetCont(i);
		Art=(Artista*)gVertexGetContent(Art1);
		if(strcmp(Art->Nombre,NombreArtista)==0)
			Art->ranking ++;
	}
}

List *ListasArtistasTOP(List *L)
{
	NodeList *i = NULL;
	Artista *A1 = NULL;

	List *Lista=listNew();
	
	int cont=0;
	for (i = L->header; i != NULL && cont != 10; i = i->next)
	{	
		cont ++;
		A1=(Artista*)nodeListGetCont(i);
		listAddNode(Lista,nodeListNew(A1));
	}
	return Lista;
}
void ListPrintArtTOP(List *ListaArtistas)
{
	NodeList *i = NULL;
	Artista *A = NULL;
	int cont = 1;

	printf("TOP 10 DE ARTISTAS\nELECTRONICA\n");
	
	for (i=ListaArtistas->header;i!=NULL;i=i->next)
	{
		A=(Artista*)nodeListGetCont(i);
		if(strcmp(A->genero,"Electronica")==0&&(A->ranking>0))
		{
			printf("%d %s \n",cont,A->Nombre);
			cont ++;
		}
	}
	
	cont=1;
	
	printf("\nPOP\n");
	for (i = ListaArtistas->header; i != NULL; i = i->next)
	{
		A=(Artista*)nodeListGetCont(i);
		if(strcmp(A->genero,"Pop")==0&&(A->ranking>0))
		{
			printf("%d %s \n",cont,A->Nombre);
			cont ++;
		}
	}
	cont=1;
	printf("\nREGGAETON\n");
	for (i = ListaArtistas->header; i != NULL; i = i->next)
	{
		A=(Artista*)nodeListGetCont(i);
		if(strcmp(A->genero,"Reggaeton")==0&&(A->ranking>0))
		{
			printf("%d %s \n",cont,A->Nombre);
			cont ++;
		}
	}
	cont=1;
	printf("\nROCK\n");
	for (i = ListaArtistas->header; i != NULL; i = i->next)
	{
		A=(Artista*)nodeListGetCont(i);
		if(strcmp(A->genero,"Rock")==0&&(A->ranking>0))
		{
			printf("%d %s \n",cont,A->Nombre);
			cont ++;
		}
	}
	cont=1;
	printf("\nSALSA\n");
	for (i = ListaArtistas->header; i != NULL; i = i->next)
	{
		A=(Artista*)nodeListGetCont(i);
		if(strcmp(A->genero,"Salsa")==0&&(A->ranking>0))
		{
			printf("%d %s \n",cont,A->Nombre);
			cont ++;
		}
	}
}
