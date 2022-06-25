#include <stdio.h>
#include <stdlib.h>

int find_x(int A[], int n, int x) {
	if (n < 0) return -1;
	if (A[n] == x) return n;
	else return find_x(A,n-1, x);
}

int main()
{
	int n;

	printf("Inserire grandezza del vettore : ");
	scanf("%d",&n);

	int A[n];

	for (int i = 0; i < n; ++i)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}

	printf("Inserisci il numero da ricercare : ");
	scanf("%d",&x);

	int find = find_x(A,n,x);
	if (find != -1) printf("Il valore ricercato e' presente in posizione : %d\n",find);
	else printf("Il valore ricercato e' assente\n");	
	
}