#include "../Musica/Biblioteca.h"


/*
PROYECTO:	LIVE PLASMA DEMO C
SITE:		
*/
#define MUSICA 49
#define LIBROS 50
#define PELICULAS 51
#define SALIR 52

void menu();

void main()
{
	List* libros = llenarLibro();
	List* autores = lenarAutores();
	int opcion = 0;
	do
	{
		menu();
		opcion = getch();

		system("cls");

		switch (opcion)
		{
			case MUSICA: {
				menuMusica(); 
				system("cls");
			}break;
			case LIBROS: {
				menuLibro();
				system("cls");
			}break; 
			case PELICULAS: {
								printf("OPCION NO IMPLEMENTADA");
								_getch();
								system("cls");
			}break;
			case SALIR: break;
			default:
				break;
		}

	} while (opcion != SALIR);
}

void menu()
{
	printf("\n\n\n\t\t\t\tDEMO LIVE PLASMA\n\t\t\t==========================\n", 163);
	printf("\t\t\t\t1. M%cSICA\n", 163);
	printf("\t\t\t\t2. LIBROS\n");
	printf("\t\t\t\t3. PELICULAS\n");
	printf("\t\t\t\t4. SALIR\n\n");

	printf("\t\t\tSELECCIONE UNA OPCI%cN[_]\n", 162);
}



