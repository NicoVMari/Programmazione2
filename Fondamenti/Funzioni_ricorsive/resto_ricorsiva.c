#include <stdio.h>
#include <stdlib.h>


int mod_r (int x,int y) {
	if (x < y)
		return x;
	else 
		return mod_r(x-y,y);
}

int main()
{
	int a,b;

	printf("Primo valore da dividere : ");
	scanf("%d",&a);
	printf("Secondo valore da dividere : ");
	scanf("%d",&b);

	int resto = mod_r(a,b);
	printf("Il resto vale : %d\n",resto);
}