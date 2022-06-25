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
		FILE *fp = fopen(argv[1],"r");
		if (fp == NULL)
		{
			printf("ERRORE nell'apertura del file\n");
			return 2;
		}
		else
		{
			Node *headlist = NULL;

			int num_nodi = lista_leggi_da_file(fp,&headlist);

			printf("\nLista scuole/temperature :\n");
			lista_visualizza(headlist);

			printf("\nScuole presenti : %d\n",num_nodi);

			float max = lista_massimo(headlist,0.0);
			printf("\nTemperatura massima : %0.0f\n",max );

			lista_cancella(&headlist);

			printf("\nLista aggiornata senza le temperature sotto i 20 gradi:\n");
			lista_visualizza(headlist);
		}
	}

	return 0;
}