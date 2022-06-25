void tailinsert(LINK *lis, int x) {
	LINK p,q;
	p=newnode();
	p-> d = x;
	p-> next = NULL;
	q = *lis;
	if (q == NULL) { 
		*lis = p;
	} 
	else {
		while (q->next != NULL) q= q->next;
		q-> next = p;
	}
}