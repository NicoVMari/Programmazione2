#include "esame.h"

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

					fscanf(fp,"%d",&head->giorno);
					fscanf(fp,"%d",&head->km);
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

					fscanf(fp,"%d",&tail->giorno);
					fscanf(fp,"%d",&tail->km);
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
	if (head == NULL) return;
	else
	{
		printf("%d , %d\n",head->giorno,head->km);
		lista_visualizza(head->next);
	}
}

void lista_trova(Node *head, int giorno)
{
	int flag = 0;

	while(head != NULL && flag == 0)
	{
		if (head->giorno == giorno) flag = 1;
		else head = head->next;
	}

	printf("I km nel giorno %d equivale a : %d\n\n",giorno,head->km);
}

Node * lista_crea_media(Node *headlist)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int somma = 0, cnt = 0, i = 0;
	double media = 0.0f;

	Node *copia = headlist;
	while(copia != NULL)
	{
		somma += copia->km;
		cnt++;
		copia = copia->next;
	}

	media = (double)somma/cnt;


	while(headlist != NULL)
	{
		if (headlist->km > media)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					head->giorno = headlist->giorno;
					head->km = headlist->km;
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

					tail->giorno = headlist->giorno;
					tail->km = headlist->km;
					tail->next = NULL;

					i++;
				}
				else
					return NULL;
			}
		}

		headlist = headlist->next;
	}

	return head;

}

void lista_visualizza_schema(Node *head)
{
	while(head != NULL)
	{
		printf("%d : ",head->giorno);
		for (int i = 0; i < head->km; ++i)
		{
			printf("*");
		}
		printf("\n");
		head = head->next;
	}
}