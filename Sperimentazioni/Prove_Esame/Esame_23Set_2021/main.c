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

			printf("Lista creata :\n");
			lista_visualizza(headlist);

			printf("\nNodi presenti : %d\n",n);

			Node *pairlist = lista_pari(headlist);

			printf("\nLista pari :\n");
			lista_visualizza(pairlist);

			int sum = lista_pari_somma(pairlist,0);
			printf("\nSomma lista pari : %d\n",sum );
		}
	}

	return 0;
}