LINK find_pos(int x, LINK p) {
	int pos=1;
	while ((pos < x) && (p!= NULL)) {
		p=p->next;
		pos+=1;
	}
	return(p);
}