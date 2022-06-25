#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

int lista_leggi_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
Node * lista_pari(Node *headlist);
int lista_pari_somma(Node *head, int sum);