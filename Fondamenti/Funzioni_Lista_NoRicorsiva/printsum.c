int printsum(LINK lis) {
	int cnt = 0;
	if (lis == NULL) return 0;
	if (lis->next == NULL) return 0;
	if (lis->next->next == NULL) return 0;
	while (lis->next->next != NULL) {
		if (lis->next->next->d == lis->next->d + lis->d){ 
		cnt = cnt +1;
		}
	lis= lis->next;
	}
	return cnt;
}