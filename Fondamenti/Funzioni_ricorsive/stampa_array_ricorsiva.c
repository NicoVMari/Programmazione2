#include <stdio.h>
#include <stdlib.h>

void printarr_rt(int A[], int n, int pos) {
	if (pos < n) {
		printf("%d\n",A[pos]);
		printarr_rt(A, n, pos+1);
	}
}

int main()
{
	int n,pos=0;

	printf("Inserire grandezza del vettore : ");
	scanf("%d",&n);

	int A[n];

	for (int i = 0; i < n; ++i)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}

	printf("\n");

	printarr_rt(A,n,pos);
}