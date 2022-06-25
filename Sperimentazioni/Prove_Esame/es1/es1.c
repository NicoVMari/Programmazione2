#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

typedef struct node
{
	int giorno;
	char nome[LEN];
	int temperatura;
	struct node *next;
}Node;

int lista_leggi_da_file(Node **headlist, FILE *fp)
{
	if (fp == NULL)
	{
		return -1;
	}
	else
	{
		Node *head = NULL, *tail = NULL, *temp = NULL;
		int i = 0;

		while(!feof(fp))
		{
			if (i == 0)
			{
				head = (Node *) malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					fscanf(fp,"%d",&head->giorno);
					fscanf(fp,"%s",head->nome);
					fscanf(fp,"%d",&head->temperatura);
					head->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE, problema nell'allocazione della zona di memoria\n");
					return -1;
				}
			}
			else
			{
				temp = (Node *) malloc(sizeof(Node));
				if (temp != NULL)
				{
					tail->next = temp;
					tail = temp;

					fscanf(fp,"%d",&tail->giorno);
					fscanf(fp,"%s",tail->nome);
					fscanf(fp,"%d",&tail->temperatura);
					tail->next = NULL; 

					i++;
				}
				else
				{
					printf("ERRORE, problema nell'allocazione della zona di memoria\n");
					return -1;
				}
			}
		}

		fclose(fp);
		*headlist = head;

		return i;
	}
}

void lista_visualizza(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n");
		return;
	}
	else
	{
		printf("%d \t| %s \t| %d\n",head->giorno,head->nome, head->temperatura);
		lista_visualizza(head->next);
	}
}

int lista_media_temperature(Node *head,int *somma,double *media,int i)
{
	if (head==NULL)
	{
		*media = (double) *somma / i;
		return 0;
	}
	else
	{
		*somma = *somma + head->temperatura;
		return lista_media_temperature(head->next, somma, media, i);
	}
}

int lista_nodi_sopra_media(Node *head, double media)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		if ( (double) head->temperatura > media)
		{
			return 1 + lista_nodi_sopra_media(head->next,media);
		}
		else
		{
			return 0 + lista_nodi_sopra_media(head->next,media);
		}
	}
}

int liste_cerca_giorno(Node *head, char str[])
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		if (!strcmp(head->nome,str))
		{
			printf("%d \t| %s \t| %d\n",head->giorno,head->nome, head->temperatura);
			return 1 + liste_cerca_giorno(head->next,str);
		}
		else
		{
			return 0 + liste_cerca_giorno(head->next,str);
		}
	}
}

int lista_cancella_giorno(Node **headlist,int n)
{
	Node *head = *headlist;
	int i = 0;

	while(head != NULL)
	{
		if (n == head->giorno)
		{
			Node *elimina = head;
			head = head->next; 

			Node *temp = *headlist;
			Node *prev = NULL;

			if (temp != NULL && temp == elimina)
			{
				*headlist = temp->next;
				free(temp); 
				return 1;
			}

			while (temp != NULL && temp != elimina)
			{
				prev = temp;
				temp = temp->next;
			}

			if (temp == NULL)
				return 1;

			prev->next = temp->next;

			free(temp);

			i++;
		}
		else
		{
			head = head->next; 
		}
	}

	return i;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE, non inserimento del file da terminale\n");
		exit(1);
	}
	else
	{
		FILE *fp = NULL;
		fp = fopen(argv[1],"r");

		Node *headlist = NULL;

		int i = lista_leggi_da_file(&headlist, fp);

		if (i == -1)
		{
			printf("ERRORE, nell'apertura del file o nell'allocazione della zona di memoria\n");
			exit(2);
		}
		else
		{
			printf("\nLista generata (%d nodi)\n",i );
			lista_visualizza(headlist);

			double media = 0.0f;
			int somma = 0;
			char str_giorno[LEN];

			lista_media_temperature(headlist,&somma,&media,i);
			printf("\nTemperatura media : %0.2f\n",media);

			int sup_media =  lista_nodi_sopra_media(headlist,media);
			printf("\nNumero di nodi strettamente superiori alla media: %d\n",sup_media);

			printf("\nInserire il nome del giorno di cui si desidera conoscere le temperature: ");
			scanf("%s",str_giorno);
			printf("Ricerca...\n");

			int occ_giorno = liste_cerca_giorno(headlist,str_giorno);
			printf("Ricerca conclusa; numero di occorrenze '%s' trovate: %d\n",str_giorno,occ_giorno);

			int giorno_eli = 0;

			do
			{
				printf("\nScegliere il numero di giorno da cancellare (tra 1 e %d): ",i );
				scanf("%d",&giorno_eli);

				if (giorno_eli < 1 || giorno_eli > 15)
				{
					printf("ERRORE, inserire un giorno compreso tra 1 e %d\n",i );
				}
			} while (giorno_eli < 1 || giorno_eli > 15);

			giorno_eli = lista_cancella_giorno(&headlist, giorno_eli);
			printf("%d nodo cancellato\n",giorno_eli );

			printf("\nLista aggiornata\n");
			lista_visualizza(headlist);
		}
	}

	return 0;
}