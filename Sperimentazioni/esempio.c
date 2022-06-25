void MergeSort(int A[], int left,int right)
{
	if (left < right)
	{
		int center = (left+right)/2;
		MergeSort(A,left,center);
		MergeSort(A,center + 1, right);
		Merge(A,left,center,right);
	}
}

void QuickSort(int A[], int left, int right)
{
	if (left < right)
	{
		int center = Partition(A,left,right);
		QuickSort(A,left, center-1);
		QuickSort(A,center+1,right);
	}
}

void move(int n, char *A, char *B, char *C)
{
	if (n == 1) printf("muovo il disco %d dalla torre A alla C\n",n );
	else
	{
		move(n-1,"A","B","C");
		printf("muovo il disco %d dalla torre A alla C\n",n-1 );
		move(n-1,"B","A","C");
	}
}

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node * lista_crea()
{
	Node *head = NULL, *tail = NULL, *temp = NULL;
	int v[] = {5,6,2,8,7}

	for (int i = 0; i < 5; ++i)
	{
		if (i==0)
		{
			head = malloc(sizeof(Node));
			if (head!=NULL) 
			{
				tail = head;
				head->data = v[i];
				head->next = NULL;			
			}
			else 
			{
				printf("impossibile creare il nodo testa\n");
				head=NULL;
			}
		}
		else 
		{
			temp = malloc(sizeof(Node));
			if (temp!=NULL)
			{
				tail->next = temp;
				tail = temp;

				tail->data = v[i];
				tail->next = NULL; 
			}
			else
			{
				printf("Impossibile creare il nodo temp\n");
				head=NULL;
			}
		}
	}

	return head;

}

void ff(int a, int b, int * c, LINK lis) 
{
	int x=1;
	if (lis != NULL)
	if (lis->d < (a*b) 
	{
		*c=(*c)+x*b;
		printf(“%d\n”,*c);
		ff(a,b+1, c, lis->next);
		printf(“%d\n”,b);
		printf(“%d\n”,*c);
	}
	else if (lis->d > (a*b)) 
	{
		printf(“%d\n”,*c);
		ff(a,b+1,c, lis->next);
		*c=(*c)+x*b;
		printf(“%d\n”,b);
		printf(“%d\n”,*c);
	}

int main() 
{
  Node *L1 = lista_crea();

  int x = 2, y = 0;

  ff(x,1,&y,L1);
  

  return 0;
}