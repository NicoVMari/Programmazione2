void printpos(LINK lis, int x) {
	int pos=1;
	while (lis != NULL) {
		if ((pos % x)==0) {
		printf(">>>> %d\n", lis->d);
		}
		pos++;
		lis= lis->next;
	}
}