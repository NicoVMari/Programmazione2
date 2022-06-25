void del_k_pair(Node **headlist,int k,int pos){
    if (*headlist != NULL){
        if ((*headlist)->data == k && pos%2 == 0)
        {
            pos++;
            Node *deltesta = *headlist;
            *headlist = (*headlist)->next;
            del_k_pai
            r(&(*headlist),k,pos);
            free(deltesta);
        }
        else
        {
            pos++;
            del_k_pair(&((*headlist)->next),k,pos);
        }
    }
}

int lsequenza(Node *head){
	int len = 0, cnt = 1;

	while(head != NULL && head->next != NULL){
		if (head->data == head->next->data){
			cnt++;
			if (cnt > len)
				len = cnt;
		}
		else
			cnt = 1;
		head = head->next;
	}

	return len;
}

/*_________________________________________________*/

void del_kpos(Node **headlist,int k){
	Node *temp = NULL;

	if (*headlist != NULL){
		if (k == 1){
			temp = (*headlist);
			(*headlist) = (*headlist)->next;
			free(temp);
		}
		else
			del_kpos(&((*headlist)->next),k-1);
	}
}

/*_________________________________________________*/

Node * lista_eccedenza(Node *l1,Node *l2){
    Node *head = NULL, *tail = NULL, *temp = NULL;
    int i = 0;

    if (l1 == NULL && l2 == NULL) return NULL;
    else{
        while(l1 != NULL && l2 != NULL){
            l1 = l1->next;
            l2 = l2->next;
        }

            while(l1 != NULL){
                if (i == 0){
                    head = (Node *)malloc(sizeof(Node));
                    if (head != NULL){
                        tail = head;

                        head->data = l1->data;
                        head->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }
                else{
                    temp = (Node *)malloc(sizeof(Node));
                    if (temp != NULL){
                        tail->next = temp;
                        tail = temp;

                        tail->data = l1->data;
                        tail->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }

                l1 = l1->next;
            }
            while(l2 != NULL){
                if (i == 0){
                    head = (Node *)malloc(sizeof(Node));
                    if (head != NULL){
                        tail = head;

                        head->data = l2->data;
                        head->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }
                else{
                    temp = (Node *)malloc(sizeof(Node));
                    if (temp != NULL){
                        tail->next = temp;
                        tail = temp;

                        tail->data = l2->data;
                        tail->next = NULL;
                        i++;
                    }
                    else
                        return NULL;
                }
                l2 = l2->next;
            }

        return head;
    }
}

/*_________________________________________________*/

void del_k_val(Node **headlist,int k){
	Node *temp = NULL;

	if (*headlist != NULL){
		if ((*headlist)->data == k){
			temp = (*headlist);
			(*headlist) = (*headlist)->next;
			free(temp);
		}
		else
			del_k_val(&((*headlist)->next),k);
	}
}

/*_________________________________________________*/

void del_between(Node **headlist, int n, int m){
    Node *del = NULL, *temp = *headlist;
    int pos = 0;

    while(temp != NULL && pos <= m){
        if (n == 0 && pos <= m){
           Node *elimina = NULL;
           if (*headlist != NULL){
               elimina = *headlist;
               *headlist = (*headlist)->next;
               free(elimina);
               pos++;
           }
        }
        else{
            if (pos >= n && pos <= m){
                del = temp;
                temp = temp->next;
                
                
                Node *prev = *headlist;
                while(prev->next != del){
                  prev = prev->next;
                }
                
                prev->next = temp;
                free(del);
                
                pos++;
            }
            else{
                pos++;
                temp = temp->next;
            }
        }
    }
}

/*_________________________________________________*/

int sum_max(Node *l1, Node *l2, int sum1, int sum2)
{
    if (l1 == NULL && l2 == NULL)
    {
        if (sum1 >= sum2) return sum1;
        else return sum2;
    }
    else
    {
        if(l1 != NULL && l2 != NULL)
        {
            sum1 += l1->data;
            sum2 += l2->data;
            return f(l1->next,l2->next,sum1,sum);
        }
        if (l1 != NULL)
        {
            sum1 += l1->data;
            return f(l1->next,l2,sum1,sum);
        }
        if (l2 != NULL)
        {
            sum2 += l2->data;
            return f(l1,l2->next,sum1,sum2);
        }
    }
}

/*_________________________________________________*/

int del_multix(Node **headlist, int x){
    Node *deltesta = NULL, *del = NULL;
    int i = 0;

    while(*headlist != NULL && (*headlist)->data%x == 0){
        deltesta = *headlist;
        *headlist = (*headlist)->next;
        free(deltesta);
        i++;
    }

    Node *temp = *headlist;

    while(temp != NULL){
        if (temp->data%x == 0){
            del = temp;
            temp = temp->next;

            Node *prev = *headlist;
            while(prev->next != del)
            {
                prev = prev->next;
            }

            prev->next = temp;
            free(del);
            i++;
        }
        else
            temp = temp->next;
    }

    return i;
}

/*_________________________________________________*/

int Isequals_after_n(Node *l1,Node *l2, int n, int pos, int esito){
    if (l1 == NULL || l2 == NULL){
        if (esito == 0)
            return 0;
        else
            return 1;
    }
    else if ((l1 != NULL && l2 != NULL) && pos < n){
        pos++;
        Isequals_after_n(l1->next,l2->next,n,pos,esito);
    }
    else{
        if (l1->data == l2->data){
            esito = 1;
            pos++;
            Isequals_after_n(l1->next,l2->next,n,pos,esito);
        }
        else{
            esito = 0;
            pos++;
            Isequals_after_n(l1->next,l2->next,n,pos,esito);
        }
    }
}

/*_________________________________________________*/

Node * list_sum(Node *l1, Node * l2){
    Node *head = NULL, *tail = NULL, *temp = NULL;
    int i = 0;

    while(l1 != NULL && l2 != NULL){
        if (i == 0){
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL){
                tail = head;

                head->data = l1->data + l2->data;
                head->next = NULL;
                i++;
            }
            else
                return NULL;       
        }
        else{
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL){
                tail->next = temp;
                tail = temp;

                tail->data = l1->data + l2->data;
                tail->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        l2 = l2->next;
        l1 = l1->next;
    }
    while(l1 != NULL){
        if (i == 0){
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL){
                tail = head;

                head->data = l1->data;
                head->next = NULL;
                i++;
            }
            else
                return NULL;       
        }
        else{
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL){
                tail->next = temp;
                tail = temp;

                tail->data = l1->data;
                tail->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        l1 = l1->next;
    }
    while(l2 != NULL){
        if (i == 0){
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL){
                tail = head;

                head->data = l2->data;
                head->next = NULL;
                i++;
            }
            else
                return NULL;       
        }
        else{
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL){
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        l2 = l2->next;
    }

    return head;
}

/*_________________________________________________*/

double lista_media(Node *lis, int *sum, int *cnt){
    if (lis != NULL){
        *sum += lis->data;
        *(cnt)++;
        lista_media(lis->next,sum,cnt);
    }
    else
        return (double) (*sum)/(*cnt);
}

/*_________________________________________________*/

int sum_pesata(Node *head, int x){
    int sum = 0, pos = 1;

    while(head != NULL){
        if (pos%x == 0){
            sum += (head->data * pos);
            pos++;
        }
        else
            pos++;
        head = head->next;
        
    return sum;
}

/*_________________________________________________*/

int sum_pesata(Node *head, int n, int m){
    int sum1 = 0, sum2 = 0, pos = 0;

    while(head != NULL && pos < m){
        if (pos < n){
            sum1 += head->data;
            pos++;
        }
        else if(pos < m){
            sum2 += head->data;
            pos++;
        }
        head = head->next;
    }

    return sum1 - sum2;
}

/*_________________________________________________*/

int occ_seq(Node *head, int x){
    int occ = 0;

    if (head == NULL) return 0;
    if (head->next == NULL) return 0; 
    if (head->next->next == NULL) return 0;
    else{
        while(head->next->next != NULL){
            if (head->data == x && head->next->data == x && head->next->next->data == x){
                occ++;
            }
            head = head->next;
        }
    }

    return occ;
}

/*_________________________________________________*/

void dup_x_pos(Node **headlist, int x, int n){
    Node *temp = *headlist;

    int pos = 1;

    while(temp != NULL){
        if (temp->data == x && pos%n == 0){
            Node *new_node = NULL;
            new_node = (Node *) malloc(sizeof(Node));
            if (new_node != NULL){
              new_node->data = x;
              new_node->next = temp->next;
              
              temp->next = new_node;
            }
            else{
                printf("ERRORE nell'allocamento del nodo\n");
                exit(2);
            }
            temp = temp->next;
            pos++;
        }
        else{
            pos++;
        }

        temp = temp->next;
    }
}

/*_________________________________________________*/

Node * f(Node *l1, Node *l2, int n, int m)
{
    Node *head = NULL, *teal = NULL, *temp = NULL;
    int pos = 0;

    while(l1 != NULL && l2 != NULL)
    {
        if (pos <= n)
        {
            if (pos == 0)
            {
                head = (Node *)malloc(sizeof(Node));
                if(head != NULL)
                {
                    tail = head;

                    head->data = l1->data;
                    head->next = NULL;
                }   
                else
                    exit(1);    
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if(temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l1->data;
                    tail->next = NULL;
                }   
                else
                    exit(1);
            }
        }
        else if (pos > n && pos < m)
        {
            temp = (Node *)malloc(sizeof(Node));
            if(temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l1->data + l2->data;
                tail->next = NULL;
            }   
            else
                exit(1);
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if(temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;
            }   
            else
                exit(1);
        }

        pos++;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 == NULL && l2 != NULL)
    {
        if (pos <= n)
        {
            return head;
        }
        else if (pos > n)
        {
            temp = (Node *)malloc(sizeof(Node));
            if(temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;
            }   
            else
                exit(1);
        }

        pos++;
        l2 = l2->next;
    }

    while(l1 != NULL && l2 == NULL)
    {
        if (pos < m)
        {
            if (pos == 0)
            {
                head = (Node *)malloc(sizeof(Node));
                if(head != NULL)
                {
                    tail = head;

                    head->data = l1->data;
                    head->next = NULL;
                }   
                else
                    exit(1);    
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if(temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l1->data;
                    tail->next = NULL;
                }   
                else
                    exit(1);
            }
        }
        else
        {
            return head;
        }
    }

    return head;
}

/*_________________________________________________*/

void del_l1(Node **l1, Node *l2, int n){
    Node *deltesta = NULL, *temp = *l1;

    while((*l1 != NULL && l2 != NULL) && ((*l1)->data+l2->data)%n == 0){
        deltesta = *l1;
        *l1 = (*l1)->next;
        l2 = l2->next;
        free(deltesta);
    }

    while(temp != NULL && l2 != NULL){
        if ((temp->data + l2->data)%2 == 0){
            Node *del = temp;
            temp = temp->next;
            l2 = l2->next;

            Node *prev = *l1;
            while(prev->next != del)
                prev = prev->next;

            prev->next = temp;
            free(del);
        }
        else{
            temp = temp->next;
            l2 = l2->next;
        }
    }
    while(temp != NULL){
        if (temp->data%2 == 0){
            Node *del = temp;
            temp = temp->next;

            Node *prev = *l1;
            while(prev->next != del)
                prev = prev->next;

            prev->next = temp;
            free(del);
        }
        else{
            temp = temp->next;
        }
    }
}

//FUNZIONI RICORSIVE

int max_occ(Node *head, int max){
    if (head == NULL){
        return 0;
    }
    else{
        if (head->data > max){
            max = head->data;
            1 + return max_occ(head->next,max);
        }
        else if (head->data == max){
            1 + return max_occ(head->next,max);
        }
        else{
            return max_occ(head->next,max);
        }
    }
}

/*_________________________________________________*/

int IsCrescente(Node *head, int esito){
    
    if (head == NULL) return 0;
    else if (head->next == NULL || esito == 0){
        return esito;
    }
    else{
        if (head->data < head->next->data){
            return IsCrescente(head->next,esito);
        }
        else{
            esito = 0;
            return IsCrescente(head->next,esito);
        }
    }
}

/*_________________________________________________*/

int equals_pos(Node *l1, Node *l2){
    if (l1 == NULL && l2 == NULL){
        return 0;
    }
    else{
        if (l1 != NULL && l2 != NULL){
            if (l1->data == l2->data){
                return 1 + equals_pos(l1->next,l2->next);
            }
            else
               return 0 + equals_pos(l1->next,l2->next); 
        }
        else if (l1 != NULL && l2 == NULL){
            if (l1->data == 0){
                return 1 + equals_pos(l1->next,l2);
            }
            else
               return 0 + equals_pos(l1->next,l2); 
        }
        else if (l1 == NULL && l2 != NULL){
            if (l2->data == 0){
                return 1 + equals_pos(l1,l2->next);
            }
            else
               return 0 + equals_pos(l1,l2->next); 
        }
    }
}

/*_________________________________________________*/

Node * list_diff_rt(Node *l1, Node *l2, int pos){
    Node *node = NULL;
    if (l1 == NULL || l2 == NULL) return NULL;
    else{
            if ((l1->data - l2->data)%2 == 0){
                pos++;

                node = (Node *)malloc(sizeof(Node));
                if (node != NULL){
                    node->data = l1->data - l2->data;
                    node->next = list_diff_rt(l1->next,l2->next,pos);
                    return node;
                }
                else{
                    printf("ERRORE nell'allocamento nodo\n");
                    exit(1);
                }
            }
            else{
                pos++;
                list_diff_rt(l1->next,l2->next,pos);
            }        
    }
}

/*_________________________________________________*/

Node * list_molt_rt(Node *l1, Node *l2, int pos){
    Node *head = NULL;

    if (l1 == NULL || l2 == NULL) return NULL;
    else{
        printf("l1->data + l2->data : %d || l1->data * l2->data : %d || pos : %d\n\n",l1->data+l2->data,l1->data*l2->data,pos);
        if ((l1->data+l2->data)%pos == 0){
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL){
                pos++;

                head->data = l1->data*l2->data;
                head->next = list_molt_rt(l1->next,l2->next,pos);
                return head;
            }
            else{
                printf("ERRORE nell'allocamento del nodo\n");
                exit(2);
            }
        }
        else
        {
            pos++;
            list_molt_rt(l1->next,l2->next,pos);
        }
    }
}