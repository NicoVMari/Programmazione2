#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 5

typedef struct node
{
	char cod_esame[DIM];
	int voto;
	int cfu;
	struct node *next;
}Node;

int lista_leggi_da_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
float lista_media(Node *head, int sum1, int sum2);
Node * lista_lodi(Node *headlist);
void lista_cerca_esame(Node *head,char str[]);