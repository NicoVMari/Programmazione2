#include <stdio.h>
#include <stdlib.h>

int sum(int A[],int n) {
	if (n == 0)
		return A[0];
	else 
		return A[n]+ sum(A,n-1) ;
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

	printf("\n");

	int somma = sum(A,n);
	printf("La somma vale : %d\n",somma);
}