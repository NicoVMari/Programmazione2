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

			printf("Lista generata : \n");
			lista_visualizza(headlist);

			printf("Node creati : %d\n\n",n);

			double media = 0.0f;
			media_positivi(headlist,0,0,&media);
			printf("Media nodi positivi : %0.2f\n\n",media);

			Node *headlistoltre = NULL;
			int n_oltre = lista_oltre_media(headlist,&headlistoltre,media);

			printf("Seconda lista con nodi positivi che superano la media:\n");
			lista_visualizza(headlistoltre);

			printf("Node creati : %d\n",n_oltre);
		}
	}

	return 0;
}