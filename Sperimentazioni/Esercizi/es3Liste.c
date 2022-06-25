#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
	char data;
	struct node *next;
} Node;

Node * lista_crea(const char s[])
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int pos = 0;

	srand((unsigned) time(NULL));
	for (int i=0; i< (int)strlen(s); i++)
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
			temp = ( Node *) malloc(sizeof(Node));
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
	printf("\nLista generata : ");
	while (head != NULL)
	{
        printf("%c -> ", head->data);
        head = head->next; 
    }
		printf("NULL\n");
}

int lista_lunghezza(Node *head)
{
	int l=0;

	while (head != NULL)
	{
        l++;
        head = head->next; 
    }

    return l;
}

int lista_vocali(Node *head)
{
	int vocali=0;

	while (head != NULL)
	{
		if (head->data == 'A' || head->data == 'E' || head->data == 'I' || head->data == 'O' || head->data == 'U' ||head->data == 'a' ||head->data == 'e' ||head->data == 'i' ||head->data == 'o' ||head->data == 'u')
		{
			vocali++;
			head = head->next;
		}
		else
        	head = head->next; 
    }

    return vocali;
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

		headlist = lista_crea(argv[1]);

		if (headlist==NULL)
		{
			printf("Lista Vuota");
			exit(2);
		}
		else
		{
			lista_visualizza(headlist);

			int l = lista_lunghezza(headlist);
			printf("Lunghezza della lista: %d\n",l);

			int nvocali = lista_vocali(headlist);
			printf("Vocali della lista: %d\n",nvocali);
		}
	}
	return 0;
}