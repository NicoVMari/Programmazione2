#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

void lista_leggi_file(FILE *fp, Node **headlist);
void lista_visualizza(Node *head);
void lista_divisibili(Node **headlist, int n);