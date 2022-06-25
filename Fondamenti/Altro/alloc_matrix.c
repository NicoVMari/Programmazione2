#include <stdio.h>
#include <stdlib.h>

int main () {
int **a;
int n,m,i,j;
printf("Inserisci la dimensione 1 (n) della matrice (nxm):  \n");
scanf("%d",&n);
printf("Inserisci la dimensione 2 (m) della matrice (nxm):  \n");
scanf("%d",&m);
    
a = (int **) malloc(n* sizeof(int*));
	for(i=0;i<n;i++) {
        a[i] = (int *) malloc(m * sizeof(int));
    }

    for(i=0;i<n;i++)  {
        for(j=0;j<m;j++)  {
            
            a[i][j] = m*i+j;
            printf("a[%d][%d] = %2d ",i,j,a[i][j]);

            
        }
        printf("\n");
    }
    
    
    /* deallocazione */
    for(i=0;i<n;i++) free(a[i]);
    free(a);

    
return 0;
}
