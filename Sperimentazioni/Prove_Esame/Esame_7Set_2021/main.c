#include "esame.h"

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("ERRORE, non inserimento degli argomenti nel terminale\n");
		exit(1);	
	}
	else if(atoi(argv[2]) < 1 || atoi(argv[2]) > 9)
	{
		printf("ERRORE, il secondo argomento deve essere compreso tra 1 e 9\n");
		exit(2);
	}
	else
	{
		FILE *fp = fopen(argv[1],"r");

		if (fp == NULL)
		{
			printf("ERRORE, nell'apertura del file\n");
			exit(3);
		}
		else
		{
			Node *headlist = NULL;
			lista_leggi_file(fp,&headlist);

			if (headlist == NULL)
			{
				printf("ERRORE, nell'allocazione della lista\n");
				exit(6);
			}
			else
			{
				printf("Lista generata :\n");
				lista_visualizza(headlist);

				lista_divisibili(&headlist,atoi(argv[2]));

				printf("Lista aggiornata :\n");
				lista_visualizza(headlist);
			}
		}
	}

	return 0;
}