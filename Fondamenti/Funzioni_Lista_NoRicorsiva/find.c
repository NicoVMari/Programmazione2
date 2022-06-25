LINK find(int x, LINK p) {
	int found=0;
	while ((p != NULL) && (! found)) {
		if (p->d==x) found=1;
		else p=p->next;
	}
	return(p);
}