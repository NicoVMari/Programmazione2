#include "esame.h"

int lista_leggi_file(FILE *fp, Node **headlist)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0, x;

	while(fscanf(fp,"%d",&x) > 0)
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
				exit(1);
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
				exit(2);
			}
		}
	}

	*headlist = head;
	fclose(fp);
	return i;
}

void lista_visualizza(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d -> ",head->data);
		return lista_visualizza(head->next);
	}
}

double media_pari(Node *head, int somma, int cnt)
{
	if (head == NULL)
	{
		return (double)(somma)/(cnt);
	}
	else
	{
		if (head->data%2 == 0)
		{
			somma += head->data;
			cnt++;
			return media_pari(head->next,somma,cnt);
		}
		else
			return media_pari(head->next,somma,cnt);
		
	}
}

int lista_negativi(Node *headlist, Node **headnegative)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(headlist != NULL)
	{
		if (headlist->data < 0)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					head->data = headlist->data;
					head->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(3);
				}
			}
			else
			{
				temp = (Node *)malloc(sizeof(Node));
				if (temp != NULL)
				{
					tail->next = temp;
					tail = temp;

					tail->data = headlist->data;
					tail->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(4);
				}
			}
		}
		headlist = headlist->next;
	}

	*headnegative = head;
	return i;
}