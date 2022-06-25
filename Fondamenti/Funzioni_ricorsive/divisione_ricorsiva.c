#include <stdio.h>
#include <stdlib.h>

int div_r (int x,int y) {
	if (x < y) return 0;
	else return 1 + div_r(x-y,y);
}

int main()
{
	int a,b;

	printf("Primo valore da dividere : ");
	scanf("%d",&a);
	printf("Secondo valore da dividere : ");
	scanf("%d",&b);

	int div = div_r(a,b);
	printf("La divisione vale : %d\n",div);
}