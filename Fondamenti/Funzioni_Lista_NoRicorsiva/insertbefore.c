void insertbefore(int x, int n, LINK *lis){
	int trovato=0;
	LINK p, head;
	head=*lis;
	if (head == NULL) {
			printf("lista vuota\n");
	} else {
			if (head->d == x) {
				p=newnode();
				p->d=n;
				p->next=head;
				*lis=p;
			} else {
					while ((head->next != NULL) && (! trovato))
							if (head->next->d == x)
									trovato=1;
							else
									head=head->next;
					if (trovato) {
						p=newnode();
						p->d=n;
						p->next=head->next;
						head->next=p;
					}
					else printf("element non trovato\n");
			}
	}
}