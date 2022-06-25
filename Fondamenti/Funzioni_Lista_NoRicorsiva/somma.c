int somma(LINK lis) {
	int tot = 0;
	while (lis != NULL) {
		tot += lis->d;
		lis= lis->next;
	}
	return tot;
}
