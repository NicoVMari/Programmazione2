void printlis(LINK lis) {
	while (lis != NULL) {
		printf("%d\n", lis->d);
		lis= lis->next;
	}
}