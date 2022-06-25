void incrementa(LINK lis) {
	while (lis != NULL) {
		lis->d += 1;
		lis= lis->next;
	}
}