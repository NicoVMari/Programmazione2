void headinsert(LINK *lis, int x) {
	LINK p;
	p=newnode();
	p->d=x;
	p->next= *lis;
	*lis=p;
}