#include <stdio.h>
#include <stdlib.h>

int prod_r (int x,int y) {
	if (y==0) return 0;
	else return x + prod_r(x,y-1);
}

int main()
{
	int a,b;

	printf("Primo valore da moltiplicare : ");
	scanf("%d",&a);
	printf("Secondo valore da moltiplicare : ");
	scanf("%d",&b);

	int prod = prod_r(a,b);
	printf("Il prodotto vale : %d\n",prod);
}