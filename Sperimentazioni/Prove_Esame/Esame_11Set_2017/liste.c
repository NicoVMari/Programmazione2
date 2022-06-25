#include "esame.h"

Node * lista_crea_file(const char nfile[])
{
	FILE *fp = fopen(nfile,"r");
	if(fp == NULL)
	{
		printf("ERRORE nell'apertura del file\n");
		exit(1);
	}
	else
	{
		Node *head = NULL, *tail = NULL, *temp = NULL;
		int i = 0, s;
		char h[DIM1],ip[DIM2];

		while(fscanf(fp,"%s %s %d",h,ip,&s) > 0)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					strcpy(head->host,h);
					strcpy(head->ip,ip);
					head->stato = s;
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

					strcpy(tail->host,h);
					strcpy(tail->ip,ip);
					tail->stato = s;
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

Node * lista_host_attivi(Node *l1)
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(l1 != NULL)
	{
		if (l1->stato == 1)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					strcpy(head->host,l1->host);
					strcpy(head->ip,l1->ip);
					head->stato = l1->stato;
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

					strcpy(tail->host,l1->host);
					strcpy(tail->ip,l1->ip);
					tail->stato = l1->stato;
					tail->next = NULL;

					i++;
				}
				else
					return NULL;
			}
		}

		l1 = l1->next;
	}

	return head;
}

void lista_visualizza(Node *head)
{
	if (head == NULL) return;
	else
	{
		printf("%s %s %d\n",head->host,head->ip,head->stato);
		return lista_visualizza(head->next);
	}
}

void lista_ricerca_host(Node *head, const char str[])
{
	int flag = 0;

	while(head != NULL && flag == 0)
	{
		if (strcmp(head->host,str) == 0) flag = 1;
		else head = head->next;
	}

	if (flag == 0) printf("host non presente\n");
	else printf("L'IP del host ricercato vale : %s\n",head->ip);
}

void lista_ordina(Node *head)
{
	Node *temp = NULL;
	while(head != NULL)
	{
		temp = head->next;
		while(temp != NULL)
		{
			if (strcmp(head->host,temp->host) > 0)
			{
				char str[DIM1];
				strcpy(str,head->host);
				strcpy(head->host,temp->host);
				strcpy(temp->host,str);
			}
			temp = temp->next;
		}
		head = head->next;
	}
}

void lista_scrivi_file(const char nfile[], Node *head)
{
	FILE *fp = fopen(nfile,"w");
	if (fp == NULL)
	{
		printf("ERRORE nell'apertura del file\n");
		exit(2);
	}
	else
	{
		while(head != NULL)
		{
			fprintf(fp,"%s %s %d\n",head->host,head->ip,head->stato);
			head = head->next;
		}

		fclose(fp);
	}
}
