#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

void inserimento_testa(Node **headlist, int x)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->data = x;
        new_node->next = *headlist;
        *headlist = new_node;
    }
    else
    {
        printf("ERRORE, nell'allocamento del node\n");
        exit(1);
    }
}

Node * lista_eccedenza(Node *l1,Node *l2)
{
    Node *head = NULL, *tail = NULL, *temp = NULL;
    int i = 0;

    if (l1 == NULL && l2 == NULL) return NULL;
    else
    {
        while(l1 != NULL && l2 != NULL)
        {
            l1 = l1->next;
            l2 = l2->next;
        }

            while(l1 != NULL)
            {
                if (i == 0)
                {
                    head = (Node *)malloc(sizeof(Node));
                    if (head != NULL)
                    {
                        tail = head;

                        head->data = l1->data;
                        head->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }
                else
                {
                    temp = (Node *)malloc(sizeof(Node));
                    if (temp != NULL)
                    {
                        tail->next = temp;
                        tail = temp;

                        tail->data = l1->data;
                        tail->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }

                l1 = l1->next;
            }

            while(l2 != NULL)
            {
                if (i == 0)
                {
                    head = (Node *)malloc(sizeof(Node));
                    if (head != NULL)
                    {
                        tail = head;

                        head->data = l2->data;
                        head->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }
                else
                {
                    temp = (Node *)malloc(sizeof(Node));
                    if (temp != NULL)
                    {
                        tail->next = temp;
                        tail = temp;

                        tail->data = l2->data;
                        tail->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }

                l2 = l2->next;
            }

        return head;
    }
}

void lista_visualizza(Node *head)
{
	while(head != NULL)
	{
		printf("%d -> ",head->data );
		head = head->next;
	}

	printf("NULL\n");
}

int main()
{
        Node *l1 = NULL, *l2 = NULL;

        int v1[] = {1,1,2,1,7,1,2}, v2[] = {2,2,1,2,1,1,1,1,1,8};

        for (int i = 6; i >= 0; --i)
        {
            inserimento_testa(&l1,v1[i]);
        }

        for (int i = 9; i >= 0; --i)
        {
            inserimento_testa(&l2,v2[i]);
        }

        Node *l3 = lista_eccedenza(l1,l2);        
        lista_visualizza(l3);

    return 0;
}