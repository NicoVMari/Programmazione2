#include "esame.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE non inserimento dei dati da terminale\n");
		return 1;
	}
	else
	{
		Node *headlist = lista_crea_file(argv[1]);

		if (headlist == NULL)
		{
			printf("ERRORE nell'allocamento del nodo\n");
			return 2;
		}
		else
		{
			printf("Dati(giorno,km) :\n");
			lista_visualizza(headlist);

			int trova_km = 0;
			printf("\nInserire un giorno di cui si vuole sapere i km : ");
			scanf("%d",&trova_km);

			if (trova_km < 1 || trova_km > 31)
			{
				printf("ERRORE, non inserimento dei giorni compreso fra 1 e 31\n");
				return 3;
			}
			else
			{
				lista_trova(headlist, trova_km);

				Node *headsupmedia = lista_crea_media(headlist);
				if (headsupmedia == NULL)
				{
					printf("ERRORE nell'allocamento del nodo\n");
					return 4;
				}
				else
				{
					printf("\nLista con i km sopra la media :\n");
					lista_visualizza(headsupmedia);

					printf("Istogramma :\n");
					lista_visualizza_schema(headlist);
				}
			}
		}
	}

	return 0;
}