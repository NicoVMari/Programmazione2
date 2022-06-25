#include <stdio.h>
#include <stdlib.h>

int sum_r (int x,int y) {
	if (y==0) return x;
	else return 1 + sum_r(x,y-1);
}

int main()
{
	int a,b;

	printf("Primo valore da sommare : ");
	scanf("%d",&a);
	printf("Secondo valore da sommare : ");
	scanf("%d",&b);

	int somma = sum_r(a,b);
	printf("La somma vale : %d\n",somma);
}