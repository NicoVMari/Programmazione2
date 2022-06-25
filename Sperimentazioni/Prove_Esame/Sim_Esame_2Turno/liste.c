#include "esame.h"

Node *lista_crea_file(const char nfile[])
{
	FILE *fp = fopen(nfile,"r");
	if (fp == NULL) return NULL;
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
					
					fscanf(fp,"%s %s %d %s",head->codice,head->titolo,&head->prezzo,head->formato);
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

					fscanf(fp,"%s %s %d %s",tail->codice,tail->titolo,&tail->prezzo,tail->formato);
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
		printf("%s\t%s\t%d\t%s\n",head->codice,head->titolo,head->prezzo,head->formato );
		return lista_visualizza(head->next);
	}
}

void lista_maxprezzo(Node *head)
{
	int maxprezzo = 0;
	Node *headmax = NULL;

	while(head != NULL)
	{
		if (head->prezzo > maxprezzo)
		{
			maxprezzo = head->prezzo;
			headmax = head;
		}
		head = head->next;
	}

	printf("\nL'album piu' costoso e' : %s\n",headmax->titolo);
}

Node * list_tipologia(Node *headlist)
{
	char form[DIMFORMATO];

	printf("Inserire una tipologia di formato (CD oppure LP) : ");
	scanf("%s",form);

	if (strcmp(form,"CD") && strcmp(form,"LP"))
	{
		printf("ERRORE, non inserimento del formato adatto\n");
		exit(1);
	}
	else
	{
		Node *head = NULL, *tail = NULL, *temp = NULL;
		int i = 0;

		while(headlist != NULL)
		{
			if (!strcmp(headlist->formato,form))
			{
				if (i == 0)
				{
					head = (Node *)malloc(sizeof(Node));
					if (head != NULL)
					{
						tail = head;

						strcpy(head->codice,headlist->codice);
						strcpy(head->titolo,headlist->titolo);
						head->prezzo = headlist->prezzo;
						strcpy(head->formato,headlist->formato);
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

						strcpy(tail->codice,headlist->codice);
						strcpy(tail->titolo,headlist->titolo);
						tail->prezzo = headlist->prezzo;
						strcpy(tail->formato,headlist->formato);
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
}

void lista_scrivi_file(Node *head,const char nfile[])
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
			fprintf(fp, "%s\t%s\t%d\t%s\n",head->codice,head->titolo,head->prezzo,head->formato);
			head = head->next;
		}

		fclose(fp);
	}
}