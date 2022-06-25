#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 16

typedef struct node
{
	char prodotto[DIM];
	int prezzo;
	int giacenza;
	struct node *next;
}Node;

Node * lista_crea_file(const char nfile[]);
Node * lista_ordinata(Node *l1);
void lista_visualizza(Node *head);
void lista_cerca(Node *head, const char str[]);
Node * lista_crea_media(Node *l1);
void lista_scrivi_file(Node *head);