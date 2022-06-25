#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 36

typedef struct node
{
	char nome[DIM];
	char professione[DIM];
	double stipendio;
	struct node *next;
}Node;

Node * lista_crea_file(FILE *fp)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(!feof(fp))
	{
		if (i == 0)
		{
			head = (Node *)malloc(sizeof(Node));
			if (head != NULL)
			{
				tail = head;

				fscanf(fp,"%s",head->nome);
				fscanf(fp,"%s",head->professione);
				fscanf(fp,"%lf",&head->stipendio);
				head->next = NULL;

				i++;

			}
			else
				return NULL;
		}
		else
		{
			temp = (Node *)malloc(sizeof(Node));
			if (temp != NULL)
			{
				tail->next = temp;
				tail = temp;

				fscanf(fp,"%s",tail->nome);
				fscanf(fp,"%s",tail->professione);
				fscanf(fp,"%lf",&tail->stipendio);
				tail->next = NULL;

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
	while(head != NULL)
	{
		printf("%s -> %s -> %0.2f milioni\n",head->nome,head->professione,head->stipendio);
		head = head->next;
	}
}

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
			printf("ERRORE nell'apertura del file\n");
			return 2;
		}
		else
		{
			Node *head = lista_crea_file(fp);
			if (head == NULL)
			{
				printf("ERRORE nell'allocamento del nodo\n");
				return 3;
			}
			else
			{
				lista_visualizza(head);
			}
		}
	}

	return 0;
}