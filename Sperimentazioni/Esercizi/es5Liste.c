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
			head =( Node *) malloc(sizeof(Node));
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

Node *lista_somma (Node *head1, Node *head2)
{
	int i=0;

	Node *listasum = NULL, *tail = NULL, *temp = NULL;

	while(head1 != NULL || head2 != NULL)
	{
		if (i==0)
			{
				listasum =( Node *) malloc(sizeof(Node));
				if (listasum!=NULL)
				{
					tail = listasum;
					listasum->data = head1->data + head2->data;
					listasum->next = NULL;
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

					tail->data = head1->data + head2->data;
					tail->next = NULL;
				}
				else
				{
					printf("Impossibile creare il Node temp\n");
					return NULL;
				}
			}
			i++;
        	head1 = head1->next;
        	head2 = head2->next;
	}

	return listasum;
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
		Node *headlist1 = NULL, *headlist2;

		headlist1 = lista_crea(atoi(argv[1]));

		if (headlist1==NULL)
		{
			printf("Lista Vuota");
			exit(2);
		}
		else
		{
			headlist2 = lista_crea(atoi(argv[1]));

			if (headlist2 == NULL)
			{
				printf("Lista Vuota");
				exit(3);
			}
			else
			{
				printf("\nPrima lista generata : ");
				lista_visualizza(headlist1);

				printf("\nPrima lista generata : ");
				lista_visualizza(headlist2);

				Node *listsum = lista_somma(headlist1,headlist2);
				printf("\nLista Somma : ");
				lista_visualizza(listsum);
			}
		}
	}
	return 0;
}