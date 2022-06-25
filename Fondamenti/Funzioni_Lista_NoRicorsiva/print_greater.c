void print_greater(LINK lis, int k) {
	while (lis != NULL) {
		if(lis->d > k ) {
			printf("%d\n", lis->d);
		}
		lis= lis->next;
	}
}
