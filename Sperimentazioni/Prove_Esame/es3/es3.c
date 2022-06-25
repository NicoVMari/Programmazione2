#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 3

typedef struct node
{
	char cod_reg[DIM];
	int dosi_somm;
	int dosi_tot;
	struct node *next;
}Node;

typedef struct node_p
{
	char cod_reg[DIM];
	double percentuale;
	struct node_p *next;
}Node_p;

Node * lista_crea_file(const char nfile[])
{
	FILE *fp = fopen(nfile,"r");
	if (fp == NULL)
	{
		printf("ERRORE nell'apertura del file\n");
		exit(1);
	}
	else
	{
		Node *head = NULL, *tail = NULL, *temp = NULL;
		int i = 0;

		while(!feof(fp))
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					fscanf(fp,"%s",head->cod_reg);
					fscanf(fp,"%d",&head->dosi_somm);
					fscanf(fp,"%d",&head->dosi_tot);
					head->next = NULL;

					i++;
				}
				else
					return NULL;
			}
			else
			{
				temp = (Node *)malloc(sizeof(Node));
				if (temp != NULL)
				{
					tail->next = temp;
					tail = temp;

					fscanf(fp,"%s",tail->cod_reg);
					fscanf(fp,"%d",&tail->dosi_somm);
					fscanf(fp,"%d",&tail->dosi_tot);
					tail->next = NULL;

					i++;
				}
				else
					return NULL;
			}
		}

		fclose(fp);
		return head;
	}
}

void lista_visualizza(Node *head)
{
	if (head == NULL)
	{
		printf("...\nNULL\n\n");
		return;
	}
	else
	{
		printf("%s\t%d\t%d\n",head->cod_reg,head->dosi_somm,head->dosi_tot);
		return lista_visualizza(head->next);
	}
}

Node_p * list_percent(Node *headlist)
{
	Node_p *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(headlist != NULL)
	{
		if (i == 0)
		{
			head = (Node_p *)malloc(sizeof(Node_p));
			if (head != NULL)
			{
				tail = head;

				strcpy(head->cod_reg,headlist->cod_reg);
				head->percentuale = (double)headlist->dosi_somm/(headlist->dosi_tot* 100);
				head->next = NULL;

				i++;
			}
			else
				return NULL;
		}
		else
		{
			temp = (Node_p *)malloc(sizeof(Node_p));
			if (temp != NULL)
			{
				tail->next = temp;
				tail = temp;

				strcpy(tail->cod_reg,headlist->cod_reg);
				tail->percentuale = (double)headlist->dosi_somm/(headlist->dosi_tot* 100);
				tail->next = NULL;

				i++;
			}
			else
				return NULL;
		}

		headlist = headlist->next;
	}

	return head;
}

void lista_visualizza2(Node_p *head)
{
	if (head == NULL)
	{
		printf("...\nNULL\n\n");
		return;
	}
	else
	{
		printf("%s\t%0.2f\n",head->cod_reg,head->percentuale * pow(10,4));
		return lista_visualizza2(head->next);
	}
}

void list_max(Node_p *head, char *reg, double *percent)
{
	if (head == NULL) return;
	else
	{
		if (head->percentuale > *percent)
		{
			*percent = head->percentuale;
			strcpy(reg,head->cod_reg);
			return list_max(head->next,reg,percent);
		}
		else
			return list_max(head->next,reg,percent);
	}
}

double lista_media(Node *head, int sum, int cnt)
{
	if (head == NULL) return (double)sum/cnt;
	else
	{
		sum += head->dosi_somm;
		cnt++;
		return lista_media(head->next,sum,cnt);
	}
}

void list_del(Node **headlist, double media)
{

	while(*headlist != NULL && (double)(*headlist)->dosi_somm > media)
	{
		Node *deltesta = *headlist;
		*headlist = (*headlist)->next;
		free(deltesta);
	}

	Node *temp = *headlist;

	while(temp != NULL)
	{
		if((double) temp->dosi_somm > media)
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

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("ERRORE, non inserimento del argomento da terminale\n");
		return 1;
	}
	else
	{
		Node *headlist = lista_crea_file(argv[1]);

		if (headlist == NULL)
		{
			printf("ERRORE, nell'allocazione delle zone di memoria\n");
			return 2;
		}
		else
		{
			printf("\nLista L1 :\n");
			lista_visualizza(headlist);

			Node_p *headpercent = list_percent(headlist);

			if (headpercent == NULL)
			{
				printf("ERRORE, nell'allocazione delle zone di memoria\n");
				return 3;
			}
			else
			{
				printf("Lista L2 :\n");
				lista_visualizza2(headpercent);

				char reg[DIM];
				double percent = 0.0f;

				list_max(headpercent,reg,&percent);
				printf("Regione con piu' dosi somministrate: %s (%0.1f)\n",reg,percent * pow(10,4));

				Node *copia = headlist;

				double media = lista_media(headlist,0,0);
				printf("\nMedia somministrazioni: %0.2f\n",media);

				list_del(&copia,media);

				printf("\nLista L1 senza i valori sompra la media:\n");
				lista_visualizza(copia);
			}
		}
	}

	return 0;
}