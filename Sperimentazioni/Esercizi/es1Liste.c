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
	printf("\nLista generata : ");
	while (head != NULL)
	{
        printf("%d -> ", head->data);
        head = head->next; 
    }
		printf("NULL\n");
}

double lista_media(Node *head,int n)
{
	int somma = 0;

	while (head != NULL)
	{
       	somma += head->data;
        head = head->next; 
    }

	return (double) somma/n;
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
			lista_visualizza(headlist);

			double media = lista_media(headlist,atoi(argv[1]));
			printf("Media voti : %f\n",media);

			FILE *fp = NULL;
			fp=fopen("lista.txt","w");

			if (fp == NULL)
			{
				printf("Errore, nell'apertura del file\n");
				exit(3);
			}
			else
			{
				while (headlist != NULL)
				{
					fprintf(fp, "%d\n",headlist->data);
			        headlist = headlist->next; 
			    }
			}

			printf("File lista.txt scritto correttamente\n");
			fclose(fp);
		}
	}
	return 0;
}