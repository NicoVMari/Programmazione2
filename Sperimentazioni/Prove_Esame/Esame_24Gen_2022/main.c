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

			int n = lista_leggi_file(fp,&headlist);

			printf("\nLista creata :\n");
			lista_visualizza(headlist);

			printf("\nNodi creati : %d\n",n);

			double media = media_pari(headlist,0,0);
			printf("\nMedia nodi con valori pari : %0.2f\n",media);

			Node *headnegative = NULL;
			int n_neg = lista_negativi(headlist,&headnegative);

			printf("\nSeconda lista con nodi negativi:\n");
			lista_visualizza(headnegative);

			printf("\nNodi creati : %d\n",n_neg);

		}
	}

	return 0;
}