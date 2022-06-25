#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 42

typedef struct node
{
	char nome[LEN];
	struct node *next;
}Node;

Node * lista_crea(FILE *fp)
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

				fscanf(fp,"%s",head->nome);
				head ->next = NULL;

				i++;
			}
			else
				return NULL;
		}
		else
		{
			temp = (Node *) malloc(sizeof(Node));
			if (temp != NULL)
			{
				tail->next = temp;
				tail = temp;

				fscanf(fp,"%s",tail->nome);
				tail ->next = NULL;

				i++;
			}
			else
				return NULL;
		}
	}

	fclose(fp);

	return head;
}

void lista_visualizza(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n\n");
	}
	else
	{
		printf("%s -> ",head->nome);
		lista_visualizza(head->next);
	}
}

int lista_lunghezza(Node *head)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + lista_lunghezza(head->next);
	}
}

void lista_cancella(char c, Node **headlist)
{
	Node *head = *headlist;

	while(head != NULL)
	{
		if (head->nome[0] == c)
		{
			Node *elimina = head;
			head = head->next; 

			Node *temp = *headlist;
			Node *prev = NULL;

			if (temp != NULL && temp == elimina)
			{
                *headlist = temp->next;
                free(temp); 
			}
			else
			{
				while (temp != NULL && temp != elimina)
				{
					prev = temp;
					temp = temp->next;
				}

				prev->next = temp->next;
				free(temp);
			}
		}
		else
			head = head->next;
	}
}

void lista_scrivi(Node *head)
{
	FILE *fp = NULL;
	fp = fopen("risultato.txt","w");

	if (fp == NULL)
	{
		printf("ERRORE, nell'apertura del file\n");
		exit(4);
	}
	else
	{
		while(head != NULL)
		{
			fprintf(fp, "%s\n",head->nome);
			head = head->next;
		}

		fclose(fp);
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("ERRORE, non inserimento dell'argomento da terminale\n");
		exit(1);
	}
	else
	{
		FILE *fp = NULL;
		fp = fopen(argv[1],"r");

		if (fp == NULL)
		{
			printf("ERRORE, nell'apertura del file\n");
			exit(2);
		}
		else
		{
			Node *headlist = NULL;
			headlist = lista_crea(fp);

			if (headlist == NULL)
			{
				printf("ERRORE, nell'allocazione delle zone di memoria\n");
				exit(3);
			}
			else
			{
				printf("\nLista : ");
				lista_visualizza(headlist);

				int l = lista_lunghezza(headlist);
				printf("Nodi nella lista: %d\n",l);

				lista_cancella(argv[2][0],&headlist);
				printf("\nLista senza '%c': ", argv[2][0]);
				lista_visualizza(headlist);

				lista_scrivi(headlist);
				printf("Lista scritta sul file risultato.txt\n");
			}
		}
	}

	return 0;
}