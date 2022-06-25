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
		Node *l1 = lista_crea_file(argv[1]);
		if (l1 == NULL)
		{
			printf("ERRORE nell'allocamento del nodo\n");
			return 2;
		}
		else
		{
			Node *l2 = lista_ordinata(l1);
			if (l2 == NULL)
			{
				printf("ERRORE nell'allocamento del nodo\n");
				return 3;
			}
			else
			{
				printf("\nLista ordinata generata :\n");
				lista_visualizza(l2);

				char str[DIM];
				printf("\nInserire il nome di un prodotto di cui si vuole sapere il prezzo e giacenza : ");
				scanf("%s",str);

				lista_cerca(l2,str);

				Node *l3 = lista_crea_media(l2);
				if (l3 == NULL)
				{
					printf("ERRORE nell'allocamento del nodo\n");
					return 3;
				}
				else
				{
					lista_scrivi_file(l2);
				}
			}
		}
	}

	return 0;
}