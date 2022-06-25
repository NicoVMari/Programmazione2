LINK findpred(int x, LINK lis) {
	int trovato=0;
	if (lis == NULL) {
		printf("lista vuota\n");
		return(NULL);
	}
	else {
		if (lis->d == x) {
			printf("%d e' a inizio lista\n", x);
			return(NULL);
		}
		else {
		while ((lis->next != NULL) && (! trovato))
			if (lis->next->d == x)
				trovato=1;
		else
			lis=lis->next;
		if (trovato)
			return(lis);
		else 
			return(NULL);
		}
	}
}