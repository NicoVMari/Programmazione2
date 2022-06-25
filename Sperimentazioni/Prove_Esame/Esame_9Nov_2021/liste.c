#include "esame.h"

int lista_leggi_file(FILE *fp, Node **headlist)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0, x;

	while(!feof(fp))
	{
		int n = fscanf(fp,"%d",&x);
		if (n > 0)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					head->data = x;
					head->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(2);
				}
			}
			else
			{
				temp = (Node *)malloc(sizeof(Node));
				if (temp != NULL)
				{
					tail->next = temp;
					tail = temp;

					tail->data = x;
					tail->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(3);
				}

			}
		}
		else
		{
			printf("ERRORE nessun byte letto\n");
			exit(1);
		}
	}

	fclose(fp);
	*headlist = head;
	return i;
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
		printf("%d -> ",head->data);
		lista_visualizza(head->next);
	}
}

int lista_negativi(Node **headlist)
{
	int i = 0;

	while(*headlist != NULL && (*headlist)->data < 0)
	{
		Node *deltesta = *headlist;
		*headlist = (*headlist)->next;
		free(deltesta);
		i++;
	}

	Node *temp = *headlist;
	while(temp != NULL)
	{
		if (temp->data < 0)
		{
			Node *del = temp;
			temp = temp->next;

			Node *prev = *headlist;
			while(prev->next != del)
				prev = prev->next;

			prev->next = temp;
			free(del);
			i++;
		}
		else
			temp = temp->next;
	}

	return i;
}

float lista_pari(Node *head, int somma, int num_pari)
{
	if (head == NULL)
	{
		return (float)somma/(float)num_pari;
	}
	else
	{
		if (head->data%2 == 0)
		{
			somma += head->data;
			num_pari++;
			return lista_pari(head->next,somma,num_pari);
		}
		else
			return lista_pari(head->next,somma,num_pari);
		
	}
}