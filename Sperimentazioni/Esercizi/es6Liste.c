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

Node * lista_vocali(Node *head,const char s[])
{
	Node *head_vocali = NULL,*tail = NULL, *temp = NULL;
	int i=0;

	while (head != NULL)
	{
		if (head->data == s[0])
		{
			head = head->next;
		}
		else
		{
			if (head->data == 'A' || head->data == 'E' || head->data == 'I' || head->data == 'O' || head->data == 'U' ||head->data == 'a' ||head->data == 'e' ||head->data == 'i' ||head->data == 'o' ||head->data == 'u')
			{
				if (i==0)
				{
					head_vocali = ( Node *)  malloc(sizeof(Node));
					if (head_vocali!=NULL)
					{
						tail = head_vocali;
						head_vocali->data = head->data;
						head_vocali->next = NULL;
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
		 
    }

    return head_vocali;
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
		Node *headlist = NULL, *headvocali = NULL;

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

			headvocali = lista_vocali(headlist,argv[2]);
			if (headvocali == NULL)
			{
				printf("Lista Vuota");
				exit(3);
			}
			else
			{
				printf("\nL2 : ");
				lista_visualizza(headvocali);
			}
		}
	}
	return 0;
}