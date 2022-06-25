int conta_multiplo(LINK lis, int k) {
	int cnt=0;
	while (lis != NULL) {
		if((lis->d %k)==0 ) {
			cnt++;
		}
		lis= lis->next;
	}
	return cnt;
}