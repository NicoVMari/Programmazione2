#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node * lista_crea_file(const char nfile[])
{
	FILE *fp=NULL;
	fp =fopen(nfile,"r");

	if (fp == NULL)
	{
		printf("Apertura del file non avvenuto correttemente\n");
		exit(2);
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
						fscanf(fp,"%d",&head->data);
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

						fscanf(fp,"%d",&tail->data);
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

	if (temp != NULL && temp == nodo)
	{
		*head = temp->next;
		free(temp); 
	}

	while (temp != NULL && temp != nodo)
	{
		temp = temp->next;
	}
}

void cancella_nodo(Node **head, int n)
{
	Node *temp = *head;

	int i = 0;

	while(temp != NULL && i < n)
	{
		Node *elimina = temp;
		temp = temp->next;  
		lista_cancella_nodo(head,elimina);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("Errore non inserimento dei dati da terminale\n");
		exit(1);
	}
	else
	{
		Node *headlist = lista_crea_file(argv[1]);

		if (headlist == NULL)
		{
			printf("Lista vuota\n");
			exit(3);
		}
		else
		{	
			printf("\nLista generata : ");
			lista_visualizza(headlist);	

			cancella_nodo(&headlist,atoi(argv[2]));
			FILE *fpw = fopen("due.txt","w");

			if (fpw == NULL)
			{
				printf("Errore nell'apertura del file\n");
				exit(5);
			}
			else
			{
				while(headlist != NULL)
				{
					fprintf(fpw, "%d\n",headlist->data);
					headlist=headlist->next;
				}

				printf("\nScrittura della lista senza i primi %d nodi sul file 'due.txt' avvenuta correttamente\n",atoi(argv[2]));
				fclose(fpw);
			}
		}
	}

	return 0;
}