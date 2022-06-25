#include "esame.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE non inserimento dei dati da terminale \n");
		return 1;
	}
	else
	{
		FILE *fp = fopen(argv[1],"r");
		if (fp == NULL)
		{
			printf("ERRORE nell'apertura del file \n");
			return 2;
		}
		else
		{
			Node *headlist = NULL;

			int n = lista_leggi_file(fp,&headlist);

			printf("\nLista creata :\n");
			lista_visualizza(headlist);

			printf("\nNodi presenti : %d\n",n);

			int num_del = lista_negativi(&headlist);

			printf("\nLista senza nodi negativi :\n");
			lista_visualizza(headlist);

			printf("\nNodi cancellati : %d\n",num_del);

			float media = lista_pari(headlist,0,0);
			printf("Media nodi con valori pari : %0.2f\n",media );
		}
	}

	return 0;
}