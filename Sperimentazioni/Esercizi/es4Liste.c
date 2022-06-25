#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int data;
	struct node *next;
} Node;

Node * lista_crea(int n)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;

	srand((unsigned) time(NULL));
	for (int i=0; i<n; i++)
	{
		if (i==0)
		{
			head = ( Node *) malloc(sizeof(Node));
			if (head!=NULL)
			{
				tail = head;
				head->data = rand()%50;
				head->next = NULL;
			}
			else
			{
				printf("impossibile creare il Node testa\n");
				return NULL;
			}
		}
		else
		{
			temp = ( Node *) malloc(sizeof(Node));
			if (temp!=NULL)
			{
				tail->next = temp;
				tail = temp;

				tail->data = rand()%50;
				tail->next = NULL;
			}
			else
			{
				printf("Impossibile creare il Node temp\n");
				return NULL;
			}
		}
	}
	return head;
}

void lista_visualizza(Node *head)
{
	while (head != NULL)
	{
        printf("%d -> ", head->data);
        head = head->next; 
    }
		printf("NULL\n");
}

Node * lista_pari(Node *head)
{
	int i=0;

	Node *listpair = NULL, *tail = NULL, *temp = NULL;

	while (head != NULL)
	{
        if (head->data%2==0)
        {	
        	if (i==0)
			{
				listpair = ( Node *) malloc(sizeof(Node));
				if (listpair!=NULL)
				{
					tail = listpair;
					listpair->data = head->data;
					listpair->next = NULL;
				}
				else
				{
					printf("impossibile creare il Node testa\n");
					return NULL;
				}
			}
			else
			{
				temp = ( Node *) malloc(sizeof(Node));
				if (temp!=NULL)
				{
					tail->next = temp;
					tail = temp;

					tail->data = head->data;
					tail->next = NULL;
				}
				else
				{
					printf("Impossibile creare il Node temp\n");
					return NULL;
				}
			}
			i++;
        	head = head->next;
        }
        else
        	head = head->next; 
    }

    return listpair;
}

Node * lista_dispari(Node *head)
{
	int i=0;

	Node *listdispair = NULL, *tail = NULL, *temp = NULL;

	while (head != NULL)
	{
        if (head->data%2==1)
        {	
        	if (i==0)
			{
				listdispair = ( Node *) malloc(sizeof(Node));
				if (listdispair!=NULL)
				{
					tail = listdispair;
					listdispair->data = head->data;
					listdispair->next = NULL;
				}
				else
				{
					printf("impossibile creare il Node testa\n");
					return NULL;
				}
			}
			else
			{
				temp = ( Node *) malloc(sizeof(Node));
				if (temp!=NULL)
				{
					tail->next = temp;
					tail = temp;

					tail->data = head->data;
					tail->next = NULL;
				}
				else
				{
					printf("Impossibile creare il Node temp\n");
					return NULL;
				}
			}
			i++;
        	head = head->next;
        }
        else
        	head = head->next; 
    }

    return listdispair;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE, non inserimento del argomento da terminale\n");
		exit(1);
	}
	else
	{
		Node *headlist = NULL;

		headlist = lista_crea(atoi(argv[1]));

		if (headlist==NULL)
		{
			printf("Lista Vuota");
			exit(2);
		}
		else
		{
			printf("\nLista generata : ");
			lista_visualizza(headlist);

			Node *pairlist = lista_pari(headlist);
			Node *dispairlist = lista_dispari(headlist);

			printf("\nLista pari : ");
			lista_visualizza(pairlist);

			printf("\nLista dispari : ");
			lista_visualizza(dispairlist);
		}
	}
	return 0;
}