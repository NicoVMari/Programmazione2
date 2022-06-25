#include "esame.h"

 int lista_leggi_file(FILE *fp, Node **headlist)
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

				fscanf(fp,"%d",&head->data);
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
			temp = (Node *) malloc(sizeof(Node));
			if (temp != NULL)
			{
				tail->next = temp;
				tail = temp;

				fscanf(fp,"%d",&tail->data);
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

Node * lista_pari(Node *headlist)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(headlist != NULL)
	{
		if(headlist->data%2 == 0)
		{
			if (i == 0)
			{
				head = (Node *) malloc(sizeof(Node));
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
					exit(4);
				}
			}
			else
			{
				temp = (Node *) malloc(sizeof(Node));
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
					exit(5);
				}
			}
		}
		
		headlist = headlist->next;
	}

	return head;
}

int lista_pari_somma(Node *head, int sum)
{
	if (head == NULL) return sum;
	else
	{
		sum += head->data;
		return lista_pari_somma(head->next,sum);
	}
}