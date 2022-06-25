#include "esame.h"

void lista_leggi_file(FILE *fp, Node **headlist)
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

				fscanf(fp,"%d",&head->data);
				head->next = NULL;

				i++;
			}
			else
			{
				printf("ERRORE, nell'allocazione del nodo\n");
				exit(4);
			}
		}
		else
		{
			temp = (Node *)malloc(sizeof(Node));
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
				printf("ERRORE, nell'allocazione del nodo\n");
				exit(5);
			}
		}
	}

	fclose(fp);
	*headlist = head;
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

void lista_divisibili(Node **headlist, int n)
{
	Node *head = *headlist;

	while(head != NULL)
	{
		if (head->data%n==0)
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