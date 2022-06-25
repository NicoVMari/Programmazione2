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
				printf("ERRORE, nell'allocazione delle zone di memoria\n");
				exit(3);
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
				printf("ERRORE, nell'allocazione delle zone di memoria\n");
				exit(4);
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
	}
	else
	{
		printf("%d -> ",head->data);
		lista_visualizza(head->next);
	}
}

Node * lista_dividi(Node *headlist,int stato)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	if (stato == 1)
	{
		while(headlist != NULL)
		{
			if (headlist->data > 0)
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
						return NULL;
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
						return NULL;
				}
			}

			headlist = headlist->next;
		}

		return head;
	}
	else
	{
		while(headlist != NULL)
		{
			if (headlist->data < 0)
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
						return NULL;
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
						return NULL;
				}
			}

			headlist = headlist->next;
		}

		return head;
	}
}

void lista_scrivi_file(Node *head, FILE *fp)
{
	while(head != NULL)
	{
		fprintf(fp, "%d\n",head->data);
		head = head->next;
	}

	fclose(fp);
}