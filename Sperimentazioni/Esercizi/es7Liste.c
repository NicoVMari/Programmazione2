#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

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
	while(head != NULL)
	{
		printf("%d -> ",head->data);
		head = head->next;
	}
	printf("NULL\n");

}

void lista_cancella_nodo(Node **head, Node *nodo)
{
	Node *temp = *head;
	Node *prev = NULL; 

	if (temp != NULL && temp == nodo)
	{
			*head = temp->next;
			free(temp);
			return;
	}

	while (temp != NULL && temp != nodo)
	{
			prev = temp;
			temp = temp->next;
	}

	if (temp == NULL)
			return;

	prev->next = temp->next;

	free(temp);

	return;
}

void cancella_dispari(Node **head)
{
	int i = 0;
	Node *temp = *head;

	while(temp != NULL)
	{
		if (i%2==1)
		{
			Node *elimina = temp;
			temp = temp->next;  
			lista_cancella_nodo(head,elimina);
			i++;
		}
		else
		{
			temp = temp->next;
			i++;
		}
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Errore non inserimento della grandezza della lista da terminale\n");
		exit(1);
	}
	else
	{
		Node *headlist = lista_crea(atoi(argv[1]));

		if (headlist == NULL)
		{
			printf("Lista vuota\n");
			exit(2);
		}
		else
		{
			printf("\nLista generata : ");
			lista_visualizza(headlist);

			cancella_dispari(&headlist);
			printf("\nLista senza nodi nella posizioni dispari : ");
			lista_visualizza(headlist);
		}
	}

	return 0;
}