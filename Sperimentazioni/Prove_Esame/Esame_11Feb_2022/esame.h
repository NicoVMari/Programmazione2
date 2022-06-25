#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

int lista_leggi_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
void media_positivi(Node *head, int sum, int cnt, double *media);
int lista_oltre_media(Node *l1, Node **l2, double media);