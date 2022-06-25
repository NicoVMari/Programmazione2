#include "esame.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE, non inserimento del argomento da terminale\n");
		exit(1);
	}
	else
	{
		FILE *fp = fopen(argv[1],"r");

		if (fp == NULL)
		{
			printf("ERRORE, nell'apertura del file\n");
			exit(2);
		}
		else
		{
			Node *headlist = NULL;
			int n = lista_leggi_file(fp,&headlist);

			printf("\nLista generata : \n");
			lista_visualizza(headlist);

			printf("Numero nodi : %d\n",n);

			Node *headpositive = NULL, *headnegative = NULL;

			headpositive = lista_dividi(headlist,1);
			headnegative = lista_dividi(headlist,-1);

			if (headnegative == NULL || headpositive == NULL)
			{
				printf("ERRORE, nell'allocazione delle zone di memoria\n");
				exit(5);
			}
			else
			{
				printf("\nLista elementi positivi : \n");
				lista_visualizza(headpositive);

				printf("\nLista elementi negativi : \n");
				lista_visualizza(headnegative);

				FILE *fplis1 = fopen("lista1.txt","w");

				if (fplis1 == NULL)
				{
					printf("ERRORE, nell'apertura del file\n");
					exit(6);
				}
				else
				{
					lista_scrivi_file(headpositive,fplis1);
				}

				FILE *fplis2 = fopen("lista2.txt","w");

				if (fplis2 == NULL)
				{
					printf("ERRORE, nell'apertura del file\n");
					exit(7);
				}
				else
				{
					lista_scrivi_file(headnegative,fplis2);
				}

			}
		}
	}

	return 0;
}