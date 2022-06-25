#include "esame.h"

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("ERRORE non inserimento dei dati da terminale \n");
		return 1;
	}
	else
	{
		Node *l1 = lista_crea_file(argv[1]);
		if (l1 == NULL)
		{
			printf("ERRORE nell'allocamento del nodo\n");
			return 2;
		}
		else
		{
			Node *l2 = lista_host_attivi(l1);
			if (l2 == NULL)
			{
				printf("ERRORE nell'allocamento del nodo\n");
				return 3;
			}
			else
			{
				printf("\nLista generata :\n");
				lista_visualizza(l1);

				printf("\nLista con gli host attivi :\n");
				lista_visualizza(l2);

				char str[DIM1];
				printf("\nInserire un host da ricercare : ");
				scanf("%s",str);

				lista_ricerca_host(l1,str);

				lista_ordina(l1);

				lista_scrivi_file(argv[2],l2);
			}
		}
	}

	return 0;
}