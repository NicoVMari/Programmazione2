#include <stdio.h>
#include <stdlib.h>


int min(int , int );
int minarr_rn(int [], int );

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

	int min = minarr_rn(A,n);
	printf("Il minore vale : %d\n",min );
}

int minarr_rn(int A[], int n) {
	if (n==0) return A[0];
	else return min(A[n],minarr_rn(A,n-1));
}

int min(int A, int B) {
	if (A<B) return A;
	else return B;
}