int elementi_minori(LINK lis) {
	int cnt=0;
	if(lis == NULL) return 0;
	if(lis->next == NULL) return 0;
	while (lis->next != NULL) {
		if(lis->d < lis->next->d ) cnt++; 
	lis= lis->next;
	}
	return cnt;
}