#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int giorno;
	int km;
	struct node *next;
}Node;

Node * lista_crea_file(const char nfile[]);
void lista_visualizza(Node *head);
void lista_trova(Node *head, int giorno);
Node * lista_crea_media(Node *headlist);
void lista_visualizza_schema(Node *head);