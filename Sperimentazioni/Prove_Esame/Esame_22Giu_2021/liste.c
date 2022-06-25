#include "esame.h"

int lista_leggi_da_file(FILE *fp, Node **headlist){
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0, n = 0;
	char cod[DIM1], nome[DIM2];
	float temperatura;


	while(!feof(fp)){
		n = fscanf(fp,"%s %s %f",cod,nome,&temperatura);
		if (n > 0){
			if (i == 0){
				head = (Node *) malloc(sizeof(Node));
				if (head != NULL){
					tail = head;

					strcpy(head->cod_s,cod);
					strcpy(head->nome_s,nome);
					head->temperatura = temperatura;
					head->next = NULL;

					i++;
				}
				else{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(1);
				}
			}
			else{
				temp = (Node *) malloc(sizeof(Node));
				if (temp != NULL){
					tail->next = temp;
					tail = temp;

					strcpy(tail->cod_s,cod);
					strcpy(tail->nome_s,nome);
					tail->temperatura = temperatura;
					tail->next = NULL;

					i++;
				}
				else{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(2);
				}
			}	
		}
		else{
			printf("Letto nessun byte dal file\n");
			exit(3);
		}
	}

	fclose(fp);
	*headlist = head;
	return i;
}

void lista_visualizza(Node *head)
{
	if (head == NULL) return;
	else
	{
		printf("%s %s %0.0f\n",head->cod_s,head->nome_s,head->temperatura);
		lista_visualizza(head->next);
	}
}

float lista_massimo(Node *head, float max)
{
	if (head == NULL) return max;
	else
	{
		if (head->temperatura > max)
		{
			max = head->temperatura;
			return lista_massimo(head->next,max);
		}
		else
			return lista_massimo(head->next,max);
	}
}

void lista_cancella(Node **headlist)
{
	while(*headlist != NULL && (*headlist)->temperatura < 20)
	{
		Node *deltesta = *headlist;
		*headlist = (*headlist)->next;
		free(deltesta);
	}

	Node *temp = *headlist;

	while(temp != NULL)
	{
		if (temp->temperatura < 20)
		{
			Node *del = temp;
			temp = temp->next;

			Node *prev = *headlist;
			while(prev->next != del)
				prev = prev->next;

			prev->next = temp;
			free(del);
		}
		else
			temp = temp->next;
	}
}