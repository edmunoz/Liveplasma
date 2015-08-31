#include "Biblioteca.h"

/*
PROYECTO: BIBLIOTECA DE MUSICA

AUTORES:
	- ANDRADE WIESNER KATHERINE DANIELA
	- GONZALEZ CHIRIBOGA CINTHYA VANESSA
	- LITARDO SANDOVAL GISELL ESTHER
	- PEÑAFIEL PEÑAFIEL CRISTINA ELIZABETH
*/
void menuMusica()
{
	Graph *Artistas = NULL, *LartistasRelacionados = NULL;
	List *Lalbum = NULL, *Lcancion = NULL, *LcancionesTOP = NULL;
	List *Lartistas = NULL, *LartistasTOP = NULL;
	int op1 = 0;
	
	Lalbum = listNew();
	Lcancion = listNew();
	LcancionesTOP = listNew();
	Lartistas = listNew();
	LartistasTOP = listNew();

	Artistas = graphNew();
	LartistasRelacionados = graphNew();
	Artistas = LlenarGraphArtistas(LlenarLAlbum(LlenarLCanciones()));
	
	system("cls");
	printf("\t\tESTRUCTURAS DE DATOS\n\nCinthya Gonzalez                                  *       *\nDaniela Andrade                                   *       *\nGisell Litardo                                 *  *       *  *\nCristina Penafiel                              *  *       *  *\n                                               *  *       *  *\n                                               *             *\n                                               *             *\n                                               *             *\n                                               ***************\n");
	_getch();
	
	do
	{
		do
		{
			system("cls");
			printf("\tBIBLIOTECA MUSICAL\n\n");
			ListaArtistasPrint(Artistas);
			printf("\n");
			printf("1.-Desea escribir el nombre de un artista\n2.-TOP 10 de las canciones\n3.-TOP 10 de artistas\n4.-Salir\n");
			op1 = getch() - 48;

			switch (op1)
			{
				case 1:
				{
						  busquedaNombreArtista(&op1, Artistas, LartistasRelacionados, Lalbum, Lcancion);
						  _getch();
				}break;
				case 2:
				{
						  topCanciones(Artistas, Lcancion, LcancionesTOP);
						  _getch();
				}break;
				case 3:
				{
						  topArtistas(Artistas, Lartistas, LartistasTOP);
						  _getch();
				}break;
			}
		} while (op1<1 || op1>4);
	} while (op1 != 4);
}

void busquedaNombreArtista(int *op1, Graph *Artistas, Graph *LartistasRelacionados, List *Lalbum, List *Lcancion)
{
	char NombreArtista[50], NombreAlbum[50], NombreCancion[50], url[200];;
	int op2 = 0;

	system("cls");
	printf("\tBIBLIOTECA MUSICAL\n");
	ListaArtistasPrint(Artistas);
	printf("Escriba el nombre de un artista tal como se muestra en el listado:\n\t");
	fflush(stdin);
	gets(NombreArtista);

	if (BuscaArtista(Artistas, NombreArtista) == 1)
	{
		system("cls");
		printf("\n1.-Lista de los albumes de %s\n2.-Lista de los artistas relacionados\n3.-Salir\nEscoja una de las opciones o presione cualquier numero para regresar al menu principal:\n\t", NombreArtista);
		scanf("%d", &op2);
		if (op2 == 1)
		{
			system("cls");
			Lalbum = ListAlbumArtista(Artistas, NombreArtista);
			OrdenarListasAlbumes(Lalbum);
			AlbumPrintList(Lalbum);
			printf("\nEscriba el nombre del album tal como se muestra en el listado:\n\t");
			fflush(stdin);
			gets(NombreAlbum);
			if (BuscarAlbum(Lalbum, NombreAlbum) == 1)
			{
				system("cls");
				Lcancion = ListCancionesAlbumPrint(Lalbum, NombreAlbum);
				printf("\nEscriba el nombre de la cancion tal como se muestra en el listado:\n\t");
				fflush(stdin);
				gets(NombreCancion);

				if (BuscarCancion(Lcancion, NombreCancion) == 1)
				{
					system("cls");
					printf("En unos instantes sera redirigido para que pueda ver el video en youtube...");
					strcpy(url, "c:\\Progra~1\\Intern~1\\iexplore.exe ");
					ActualizarGrafo(Artistas, NombreCancion, NombreAlbum, url);
					system(url);
				}
				else
					printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");

			}
			else
				printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");
		}
		if (op2 == 2)
		{
			system("cls");
			printf("\tArtistas relacionados a %s\n", NombreArtista);
			LartistasRelacionados = ListArtistasRelacionados(Artistas, NombreArtista);
			ListaArtistasPrint(LartistasRelacionados);
			printf("\nEscriba el nombre de un artista tal como se muestra en el listado:\n\t");
			fflush(stdin);
			gets(NombreArtista);
			if (BuscaArtista(LartistasRelacionados, NombreArtista) == 1)
			{
				system("cls");
				Lalbum = ListAlbumArtista(Artistas, NombreArtista);
				OrdenarListasAlbumes(Lalbum);
				AlbumPrintList(Lalbum);
				printf("\nEscriba el nombre del album tal como se muestra en el listado:\n\t");
				fflush(stdin);
				gets(NombreAlbum);
				if (BuscarAlbum(Lalbum, NombreAlbum) == 1)
				{
					system("cls");
					Lcancion = ListCancionesAlbumPrint(Lalbum, NombreAlbum);
					printf("\nEscriba el nombre de la cancion tal como se muestra en el listado:\n\t");
					fflush(stdin);
					gets(NombreCancion);
					if (BuscarCancion(Lcancion, NombreCancion) == 1)
					{
						system("cls");
						printf("En unos instantes sera redirigido para que pueda ver el video en youtube...");
						strcpy(url, "c:\\Progra~1\\Intern~1\\iexplore.exe ");
						ActualizarGrafo(Artistas, NombreCancion, NombreAlbum, url);
						system(url);
					}
					else
						printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");

				}
				else
					printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");
			}
			else
				printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");
		}
		if (op2 == 3)
			op1 = 4;
	}
	else
		printf("\nNombre Incorrecto, presione una tecla para volver a empezar. ");
}

void topCanciones(Graph *Artistas, List *Lcancion, List *LcancionesTOP)
{
	Lcancion = ListCanciones(Artistas);
	OrdenarListasCanciones(Lcancion);
	LcancionesTOP = ListasCancionesTOP(Lcancion);
	ListPrintCanTOP(LcancionesTOP);
}

void topArtistas(Graph *Artistas, List *Lartistas, List *LartistasTOP)
{
	Lartistas = ListArtistas(Artistas);
	OrdenarListasArtistas(Lartistas);
	LartistasTOP = ListasArtistasTOP(Lartistas);
	ListPrintArtTOP(LartistasTOP);
}