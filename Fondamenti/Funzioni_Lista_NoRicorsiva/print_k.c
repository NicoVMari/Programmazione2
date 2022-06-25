
void print_k(LINK lis, int k) {
	int pos=1;
	while ((lis != NULL) && (pos <= k)) {
		printf("%d\n", lis->d);
		lis=lis->next;
		pos++;
	}
}