#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

void lista_crea(Node **headList)
{
	Node *head = NULL; 
	Node *tail = NULL; 	
	Node *temp = NULL; 	

	int v[]={7,5,2,5,8};

	for (int i=0; i<5; i++) 
	{
		if (i==0)
		{
			head = malloc(sizeof(Node));
			if (head!=NULL) 
			{
				tail = head;
				head->data = v[i];
				head->next = NULL;			
			}
			else 
			{
				printf("impossibile creare il nodo testa\n");
				head=NULL;
			}
		}
		else 
		{
			temp = malloc(sizeof(Node));
			if (temp!=NULL)
			{
				tail->next = temp;
				tail = temp;

				tail->data = v[i];
				tail->next = NULL; 
			}
			else
			{
				printf("Impossibile creare il nodo temp\n");
				head=NULL;
			}
		}
	}
	*headList = head;
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

Node * ricerca_valore(Node *head,int x)
{
	Node *headpos = NULL;     
    
    Node *current = head;
    int i = 0, flag = 0;

    while(current != NULL && flag == 0)
    {
        if (current->data == x)
        {
            headpos = malloc(sizeof(Node));
            if (headpos!=NULL) 
            {
                headpos->data = i;
                headpos->next = NULL; 
                flag = 1;           
            }
        }
        i++;
        current = current->next;
    }

    return headpos;
}

int main()
{
	Node *headList = NULL;

    lista_crea(&headList);

	if (headList!=NULL)
	{
		printf("\nLista: ");
		lista_visualizza(headList);

		int p = 2;

		Node *headPosition = NULL;
		headPosition = ricerca_valore(headList,p);

		if (headPosition != NULL)
		{
			printf("\nRiferimento data -> %d",headPosition->data);
		}
		else
		{
			printf("Il valore cercato non e' presente nella lista\n");
			return 2; 
		}
	}
	else
	{
		printf("Lista vuota\n");
		return 1; 
	}

	printf("\n");

	return 0; 
}