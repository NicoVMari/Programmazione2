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

	fclose(fp);
	*headlist = head;
	return i;
}

void lista_visualizza(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n\n");
		return;
	}
	else
	{
		printf("%d -> ",head->data);
		lista_visualizza(head->next);
	}
}

void media_positivi(Node *head, int sum, int cnt, double *media)
{
	if (head == NULL)
	{
		*media = (double)sum/cnt;
		return;
	} 
	else
	{
		if (head->data > 0)
		{
			cnt++;
			sum += head->data;
			return media_positivi(head->next,sum,cnt,media);
		}
		else
			return media_positivi(head->next,sum,cnt,media);
	}
}

int lista_oltre_media(Node *l1, Node **l2, double media)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(l1 != NULL)
	{
		if (l1->data > media)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					head->data = l1->data;
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

					tail->data = l1->data;
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
		
		l1 = l1->next;
	}

	*l2 = head;
	return i;
}