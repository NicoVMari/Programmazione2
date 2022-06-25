#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

int lista_leggi_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
double media_pari(Node *head, int somma, int cnt);
int lista_negativi(Node *headlist, Node **headnegative);