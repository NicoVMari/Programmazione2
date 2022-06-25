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

			int n = lista_leggi_da_file(fp,&headlist);

			printf("Lista esami :\n");
			lista_visualizza(headlist);

			printf("\nEsami sostenuti : %d\n\n",n);

			float media = lista_media(headlist,0,0);
			printf("Media esami : %0.2f\n\n",media);

			Node *headlode = lista_lodi(headlist);

			printf("Esami con la lode:\n");
			lista_visualizza(headlode);

			Node *copia = headlist;

			char str[DIM];
			printf("\nInserire un codice esame: ");
			scanf("%s",str);

			lista_cerca_esame(copia,str);
		}
	}

	return 0;
}