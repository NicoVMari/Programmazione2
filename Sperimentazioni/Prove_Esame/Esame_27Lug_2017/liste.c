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
		int i = 0,pre,g;
		char p[DIM];

		while(fscanf(fp,"%s %d %d",p,&pre,&g) > 0)
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					strcpy(head->prodotto,p);
					head->prezzo = pre;
					head->giacenza = g;
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

					strcpy(tail->prodotto,p);
					tail->prezzo = pre;
					tail->giacenza = g;
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

Node * lista_ordinata(Node *l1)
{
	Node *temp = NULL, *copia = l1;
	while(l1 != NULL)
	{
		temp = l1->next;
		while(temp != NULL)
		{
			if (l1->prezzo > temp->prezzo)
			{
				int c = l1->prezzo;
				l1->prezzo = temp->prezzo;
				temp->prezzo = c;
			}
			temp = temp->next;
		}
		l1 = l1->next;
	}

	Node *head = NULL, *tail = NULL;
	temp = NULL;
	int i = 0;

	while(copia != NULL)
	{
		if (i == 0)
		{
			head = (Node *)malloc(sizeof(Node));
			if (head != NULL)
			{
				tail = head;

				strcpy(head->prodotto,copia->prodotto);
				head->prezzo = copia->prezzo;
				head->giacenza = copia->giacenza;
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

				strcpy(tail->prodotto,copia->prodotto);
				tail->prezzo = copia->prezzo;
				tail->giacenza = copia->giacenza;
				tail->next = NULL;

				i++;
			}
			else
				return NULL;
		}
		copia = copia->next;
	}

	return head;
}

void lista_visualizza(Node *head)
{
	if (head == NULL) return;
	else
	{
		printf("%s %d %d\n",head->prodotto,head->prezzo,head->giacenza );
		return lista_visualizza(head->next);
	}
}

void lista_cerca(Node *head, const char str[])
{
	int flag = 0;

	while(head != NULL && flag == 0)
	{
		if (!strcmp(head->prodotto,str)) flag = 1;
		else head = head->next;
	}

	if (flag == 0) printf("Prodotto non presente\n\n");
	else printf("Il prodotto cercato costa %d e una giacenza di %d\n\n",head->prezzo,head->giacenza);
}

Node * lista_crea_media(Node *l1)
{
	Node *copia = l1;
	int somma = 0, cnt = 0;

	while(l1 != NULL)
	{
		somma += l1->prezzo;
		cnt++;
		l1 = l1->next;
	}

	Node *head = NULL, *tail = NULL, *temp = NULL;
	int i = 0;

	while(copia != NULL)
	{
		if (copia->prezzo > ((double)somma/cnt))
		{
			if (i == 0)
			{
				head = (Node *)malloc(sizeof(Node));
				if (head != NULL)
				{
					tail = head;

					strcpy(head->prodotto,copia->prodotto);
					head->prezzo = copia->prezzo;
					head->giacenza = copia->giacenza;
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

					strcpy(tail->prodotto,copia->prodotto);
					tail->prezzo = copia->prezzo;
					tail->giacenza = copia->giacenza;
					tail->next = NULL;

					i++;
				}
				else
					return NULL;
			}
		}
		copia = copia->next;
	}

	printf("Lista con il prezzo sopra la media :\n");
	lista_visualizza(head);
	return head;
}

void lista_scrivi_file(Node *head)
{
	FILE *fp = fopen("dati_ordinati.txt","w");
	if (fp == NULL)
	{
		printf("ERRORE nell'apertura del file \n");
		exit(2);
	}
	else
	{
		while(head != NULL)
		{
			fprintf(fp,"%s %d %d\n",head->prodotto,head->prezzo,head->giacenza );
			head = head->next;
		}
	}
}