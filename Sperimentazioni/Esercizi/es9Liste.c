#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *next;
} Node;

Node * lista_crea(const char s[])
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int pos = 0;

	for (int i=0; i< (int) strlen(s); i++)
	{
		if (i==0)
		{
			head = ( Node *) malloc(sizeof(Node));
			if (head!=NULL)
			{
				tail = head;
				head->data = s[pos];
				head->next = NULL;
				pos++;
			}
			else
			{
				printf("impossibile creare il Node testa\n");
				return NULL;
			}
		}
		else
		{
			temp =( Node *)  malloc(sizeof(Node));
			if (temp!=NULL)
			{
				tail->next = temp;

				tail = temp;

				tail->data = s[pos];
				tail->next = NULL;
				pos++;
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
        printf("%c -> ", head->data);
        head = head->next; 
    }
		printf("NULL\n");
}

void lista_cancella_nodo(Node **head, Node *nodo)
{
	Node *temp = *head;
	Node *prev = NULL; // precedente

	// se la testa contiene il nodo cercato (confronto tra indirizzi)
	if (temp != NULL && temp == nodo)
	{
			*head = temp->next; // cambia la testa
			free(temp); // cancella la vecchia testa
			return;
	}

	// cerca il nodo da cancellare nei nodi
	// tenendo traccia del nodo precedente rispetto a quello cercato
	while (temp != NULL && temp != nodo) // confronto tra indirizzi
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

void cancella_carattere(Node **head,char c)
{
	int i = 0;
	Node *temp = *head;

	while(temp != NULL)
	{
		if (temp->data==c)
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
	if (argc != 3)
	{
		printf("ERRORE, non inserimento del argomento da terminale\n");
		exit(1);
	}
	else
	{
		Node *headlist = NULL;

		headlist = lista_crea(argv[1]);

		if (headlist==NULL)
		{
			printf("Lista Vuota");
			exit(2);
		}
		else
		{
			printf("\nL1 : ");
			lista_visualizza(headlist);

			cancella_carattere(&headlist,argv[2][0]);
			printf("\nEliminati i nodi nelle posizioni dove e' presente il carattere '%c'\n",argv[2][0]);
			printf("\nLista senza carattere %c : ",argv[2][0]);
			lista_visualizza(headlist);
			
		}
	}
	return 0;
}