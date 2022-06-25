#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMCODICE 6
#define DIMTITOLO 8
#define DIMFORMATO 2

typedef struct node
{
	char codice[DIMCODICE];
	char titolo[DIMTITOLO];
	int prezzo;
	char formato[DIMFORMATO];
	struct node *next;	
}Node;
Node *lista_crea_file(const char nfile[]);
void lista_visualizza(Node *head);
void lista_maxprezzo(Node *head);
Node * list_tipologia(Node *headlist);
void lista_scrivi_file(Node *head,const char nfile[]);