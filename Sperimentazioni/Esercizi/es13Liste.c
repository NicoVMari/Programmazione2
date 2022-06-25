#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

typedef struct node{

	char nome[LEN];
	struct node *next;

}Node;

Node * lista_crea(const char nfile[])
{
	FILE *fp = fopen(nfile,"r");

	if (fp == NULL)
	{
		printf("Errore nell'apertura del file\n");
		exit(3);
	}
	else
	{
		Node *head = NULL, *tail = NULL, *temp = NULL;
		int i = 0;

		while(!feof(fp))
		{
			if (i==0)
			{
				i++;
				head = ( Node *) malloc(sizeof(Node));
				if (head!=NULL)
				{
					tail = head;
					fscanf(fp,"%s",head->nome);
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
				i++;
				temp = ( Node *) malloc(sizeof(Node));
				if (temp!=NULL)
				{
					tail->next = temp;
					tail = temp;

					fscanf(fp,"%s",tail->nome);
					tail->next = NULL;
				}
				else
				{
					printf("Impossibile creare il Node temp\n");
					return NULL;
				}
			}
		}

		fclose(fp);

		return head;
	}
}

void lista_visualizza(Node *head)
{
    if(head == NULL)
	{
        printf("NULL\n\n");
    }
    else
    {
    	printf("%s -> ", head->nome);
        lista_visualizza(head->next);
    }
}

void conta_vocali(Node *head)
{
	int vocali;

	while(head != NULL)
	{
		vocali = 0;
		for (int i = 0; head->nome[i] != '\0'; ++i)
		{
			if (head->nome[i] == 'A' || head->nome[i] == 'E' || head->nome[i] == 'I' || head->nome[i] == 'O' || head->nome[i] == 'U' || head->nome[i] == 'a' || head->nome[i] == 'e' || head->nome[i] == 'i' || head->nome[i] == 'o' || head->nome[i] == 'u')
			{
				vocali++;
			}
		}
		printf("%s contine %d vocali\n",head->nome,vocali );
		head = head->next;
	}
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

void cancella_carattere(Node **head,char c)
{
	int i = 0;
	Node *temp = *head;

	while(temp != NULL)
	{
		if (temp->nome[0]==c)
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
		printf("Errore, non inserimento del file da terminale\n");
		exit(1);
	}
	else
	{
		Node *headlist = NULL;
		headlist = lista_crea(argv[1]);

		if (headlist != NULL)
		{
			lista_visualizza(headlist);

			conta_vocali(headlist);

			char c;

			printf("\nInserire una lettera da eliminare : ");
			scanf("%c",&c);

			cancella_carattere(&headlist,c);
			
			FILE *fpw = fopen("dati.txt","w");

			if (fpw != NULL)
			{
				while(headlist != NULL)
				{
					fprintf(fpw, "%s -> ",headlist->nome);
					headlist = headlist->next;
				}
				fprintf(fpw, "%s\n", "NULL");

				printf("Lista senza nomi che iniziano con '%c' scritta correttemente sul file : 'dati.txt'\n",c);
			}
			else
			{
				printf("Errore nell'apertura del file\n");
				exit(5);
			}
		}
		else
		{
			printf("Errore nella crezione nella lista\n");
			exit(2);
		}

	}

	return 0;
}