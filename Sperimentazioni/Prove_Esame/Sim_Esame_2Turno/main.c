#include "esame.h"


int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("ERRORE non inserimento dei dati da terminale\n");
		return 1;
	}
	else
	{
		Node *headlist = lista_crea_file(argv[1]);
		if (headlist == NULL)
		{
			printf("ERRORE nell'allocamento del nodo o nell'apertura del file\n");
			return 2;
		}
		else
		{
			printf("\nLista generata :\n");
			lista_visualizza(headlist);

			lista_maxprezzo(headlist);

			Node *headformato = list_tipologia(headlist);
			if (headformato == NULL)
			{
				printf("ERRORE nell'allocamento del nodo o nell'apertura del file\n");
				return 3;
			}
			else
			{
				lista_scrivi_file(headformato,argv[2]);
				printf("Scrittura della seconda lista su file avvenuta correttamente\n");
			}
		}
	}

	return 0;
}