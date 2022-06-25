#include "esame.h"

int lista_leggi_da_file(FILE *fp, Node **headlist)
{
	Node *head = NULL,*tail = NULL, *temp = NULL;
	int i = 0;

	while(!feof(fp))
	{
		if (i == 0)
		{
			head = (Node *)malloc(sizeof(Node));
			if (head != NULL)
			{
				tail = head;

				fscanf(fp,"%s %d %d",head->cod_esame,&head->voto,&head->cfu);
				head->next = NULL;

				i++;
			}
			else
			{
				printf("ERRORE nell'allocamento del nodo\n");
				exit(1);
			}
		}
		else
		{
			temp = (Node *)malloc(sizeof(Node));
			if (temp != NULL)
			{
				tail->next = temp;
				tail = temp;

				fscanf(fp,"%s %d %d",tail->cod_esame,&tail->voto,&tail->cfu);
				tail->next = NULL;

				i++;
			}
			else
			{
				printf("ERRORE nell'allocamento del nodo\n");
				exit(2);
			}
		}
	}

	*headlist = head;
	fclose(fp);
	return i;
}

void lista_visualizza(Node *head)
{
	if (head == NULL) return;
	else
	{
		printf("%s\t%d\t%d\n",head->cod_esame,head->voto,head->cfu);
		return lista_visualizza(head->next);
	}
}

float lista_media(Node *head, int sum1, int sum2)
{
	if (head == NULL) return (float)(sum1/sum2);
	else
	{
		sum1 += (head->voto * head->cfu);
		sum2 += head->cfu;
		return lista_media(head->next,sum1,sum2);
	}
}

Node * lista_lodi(Node *headlist)
{
	Node *head = NULL,*tail = NULL, *temp = NULL;
	int i = 0;

	while(headlist != NULL)
	{
		if (headlist->voto == 31)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					strcpy(head->cod_esame,headlist->cod_esame);
					head->voto = headlist->voto;
					head->cfu = headlist->cfu;
					head->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(3);
				}
			}
			else
			{
				temp = (Node *)malloc(sizeof(Node));
				if (temp != NULL)
				{
					tail->next = temp;
					tail = temp;

					strcpy(tail->cod_esame,headlist->cod_esame);
					tail->voto = headlist->voto;
					tail->cfu = headlist->cfu;
					tail->next = NULL;

					i++;
				}
				else
				{
					printf("ERRORE nell'allocamento del nodo\n");
					exit(4);
				}
			}
		}
	
		headlist = headlist->next;
	}

	return head;
}

void lista_cerca_esame(Node *head,char str[])
{
	int flag = 0;

	while(head != NULL && flag == 0)
	{
		if (strcmp(head->cod_esame,str) == 0) flag = 1;
		else head = head->next;
	}

	if (flag == 0)
		printf("Esame non trovato / non ancora sostenuto\n");
	else
		printf("%s\t%d\t%d\n",head->cod_esame,head->voto,head->cfu);
	
}