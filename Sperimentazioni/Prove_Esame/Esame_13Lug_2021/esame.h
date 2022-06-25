#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

int lista_leggi_file(FILE *, Node **);
void lista_visualizza(Node *);
Node * lista_dividi(Node *,int );
void lista_scrivi_file(Node *, FILE *);