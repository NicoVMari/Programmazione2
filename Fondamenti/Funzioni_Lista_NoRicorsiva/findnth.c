LINK findnth(int x, int n, LINK lis) {
	int cnt=0;
	int trovato=0;
	while ((lis != NULL) && (!trovato)) { 
		lis=find(x,lis);
			if (lis != NULL)
				if (cnt+1 == n) trovato=1;
				else {
					cnt=cnt+1;
					lis=lis->next;
				}
	}
	return lis;
}