#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM1 6
#define DIM2 15
typedef struct node
{
	char host[DIM1];
	char ip[DIM2];
	int stato;
	struct node *next;
}Node;


Node * lista_crea_file(const char nfile[]);
Node * lista_host_attivi(Node *l1);
void lista_visualizza(Node *head);
void lista_ricerca_host(Node *head, const char str[]);
void lista_ordina(Node *head);
void lista_scrivi_file(const char nfile[], Node *head);