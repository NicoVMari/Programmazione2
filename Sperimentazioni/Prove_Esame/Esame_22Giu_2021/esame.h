#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM1 6
#define DIM2 32

typedef struct node{
	char cod_s[DIM1];
	char nome_s[DIM2];
	float temperatura;
	struct node *next;
}Node;

int lista_leggi_da_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
float lista_massimo(Node *head, float max);
void lista_cancella(Node **headlist);