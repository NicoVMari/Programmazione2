#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STUDENTE {
char cognome[20];
char nome[20];
int anno_nascita;
} Studente;




void carica(Studente A[], int n) {
int i;
for (i=0; i<n; i++) {
    printf("Cognome della persona %d \n",i);
    scanf("%s",(A[i].cognome));
    printf("Nome della persona %d \n",i);
    scanf("%s",(A[i].nome));
    printf("Anno di nascita della persona %d \n", i);
    scanf ("%d",&(A[i].anno_nascita));
    }
}

void stampa (Studente A[], int n){
int i;
for (i=0; i<n; i++){
    printf("Cognome %s \n",A[i].cognome);
    printf("Nome %s \n", A[i].nome);
    printf("Anno nascita %d \n", A[i].anno_nascita);
    }
}

void dividi(Studente A[], int n, Studente B[], int *nB, Studente C[], int *nC) {
int i;
*nB = 0;
*nC = 0;
    for (i=0; i<n; i++) {
        if (A[i].anno_nascita < 2004) {
            strcpy (B[*nB].cognome,A[i].cognome);
            strcpy (B[*nB].nome,A[i].nome);                                     
            B[*nB].anno_nascita=A[i].anno_nascita;
            (*nB)++;
        } else {
            strcpy (C[*nC].cognome,A[i].cognome);
            strcpy (C[*nC].nome,A[i].nome);
            C[*nC].anno_nascita=A[i].anno_nascita;
            (*nC)++;
        }
    }
}


int main () {
    int nB = 0;
    int nC = 0;

    Studente elenco[3];
    Studente B[3];
    Studente C[3];
    carica(elenco,3);
    //stampa(elenco, 3);
    //void dividi(Studente A[], int n, Studente B[], int *nB, Studente C[], int *nC) {

    dividi(elenco,3,B,&nB,C,&nC);
    printf("Maggiorenni\n");
    stampa(B,nB);
    printf("Minorenni\n");
    stampa(C,nC);
    
    return 0;
}




