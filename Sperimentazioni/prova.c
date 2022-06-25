typedef struct node
{
    int data;
    struct node *next;
}Node;

int f1(Node *head)
{
    int cnt = 1, max = 0;

    if (head == NULL) return 0;
    if (head->next == NULL) return 0;
    else
    {
        while(head->next != NULL)
        {
            if (head->data == head->next->data)
            {
                cnt++;
                if (cnt > max)
                {
                    max = cnt;
                }
            }
            else
                cnt = 1;

            head = head->next;
        }
    }
}

void f2(Node **headlist, int k)
{
    if ((*headlist) != NULL)
    {
        if (k == 1)
        {
            Node *del = *headlist;
            *headlist = (*headlist)->next;
            free(del);
        }
        else
            f2(&((*headlist)->next), k-1);
    }
}

Node * f3(Node *l1, Node *l2)
{
    if (l1 == NULL && l2 == NULL) return NULL;
    else
    {
        Node *head = NULL, *tail = NULL, *temp = NULL;
        int i = 0;

        while(l1 != NULL || l2 != NULL)
        {
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            if (i == 0)
            {
                head = (Node *)malloc(sizeof(Node));
                if (head != NULL)
                {
                    tail = head;

                    head->data = l1->data;
                    head->next = NULL;

                    i++;
                }
                else
                    return NULL;
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if (temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l1->data;
                    tail->next = NULL;

                    i++;
                }
            }
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            if (i == 0)
            {
                head = (Node *)malloc(sizeof(Node));
                if (head != NULL)
                {
                    tail = head;

                    head->data = l2->data;
                    head->next = NULL;

                    i++;
                }
                else
                    return NULL;
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if (temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l2->data;
                    tail->next = NULL;

                    i++;
                }
            }
            l2 = l2->next;
        }

        return head;
    }
}

void f4(Node **headlist, int k)
{
    if ((*headlist) != NULL)
    {
        if ((*headlist)->data == k)
        {
            Node *del = *headlist;
            *headlist = (*headlist)->next;
            free(del);
        }
        else
            f2(&((*headlist)->next), k);
    }
}

void f5(Node **headlist, int n, int m)
{
    int pos = 0;

    if (n == 0)
    {
        while(*headlist != NULL && pos < m)
        {
            pos++;
            Node *deltesta = *headlist;
            *headlist = (*headlist)->next;
            free(deltesta);
        }
    }

    Node *temp = *headlist;
    while(pos < n)
    {
        pos++;
        temp = temp->next;
    }

    while(temp != NULL && pos < m)
    {
        pos++;
        Node *del = temp;
        temp = temp->next;

        Node *prev = *headlist;
        while(prev->next != del)
            prev = prev->next;

        prev->next = temp;
        free(del);
    }
}

int f6(Node *l1, Node *l2, int sum1, int sum2)
{
    if (l1 == NULL && l2 == NULL)
    {
        if (sum1 >= sum2) return sum1;
        else return sum2;
    }
    else
    {
        if (l1 != NULL && l2 != NULL)
        {
            sum1 += l1->data;
            sum2 += l2->data;
            return f6(l1->next,l2->next,sum1,sum2);
        }
        else
        {
            if (l1 != NULL)
            {
                sum1 += l1->data;
                return f6(l1->next,l2,sum1,sum2);
            }
            if (l2 != NULL)
            {
                sum2 += l2->data;
                return f6(l1->next,l2,sum1,sum2);
            }
        }
    }
}

int f7(Node **headlist, int x)
{
    int cnt = 0;

    while(*headlist != NULL)
    {
        if ((*headlist)->data%x == 0)
        {
            Node *deltesta = *headlist;
            *headlist = (*headlist)->next;
            free(deltesta);
            cnt++;
        }
        else
            break;
    }

    Node *temp = *headlist;
    while(temp != NULL)
    {
        if (temp->data%x == 0)
        {
            cnt++;
            Node *del = temp;
            temp = temp->next;

            Node *prev = *headlist;
            while(prev->next != del)
                prev = prev->next;

            prev->next = temp;
            free(del);
        }
        else
            temp = temp->next;
    }

    return cnt;
}

//esito inizializatto ad 1 e pos a 0
int f8(Node *l1, Node *l2, int n, int pos, int esito)
{
    if (l1 == NULL || l2 == NULL) return esito;
    {
        if (pos < n)
        {
            pos++;
            return f8(l1->next,l2->next,n,pos);
        }
        else
        {
            if (l1->data != l2->data)
            {
                esito = 0;
                return esito;
            }
            else
                return f8(l1->next,l2->next,n,pos);
            
        }
    }
}

Node * f9(Node *l1, Node *l2)
{
    Node *head = NULL, *tail = NULL, *temp = NULL;
    int i = 0;

    while(l1 != NULL || l2 != NULL)
    {
        if (i == 0)
        {
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL)
            {
                tail = head;

                head->data = l1->data + l2->data;
                head->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l1->data + l2->data;
                tail->next = NULL;

                i++;
            }
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL)
    {
        if (i == 0)
        {
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL)
            {
                tail = head;

                head->data = l1->data;
                head->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l1->data;
                tail->next = NULL;

                i++;
            }
        }
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        if (i == 0)
        {
            head = (Node *)malloc(sizeof(Node));
            if (head != NULL)
            {
                tail = head;

                head->data = l2->data;
                head->next = NULL;

                i++;
            }
            else
                return NULL;
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;

                i++;
            }
        }
        l2 = l2->next;
    }

    return head;
}

//con somma e pos inizializzate entrambe a 0
double f10(Node *head, int somma, int pos)
{
    if (head == NULL) return (double)somma/pos;
    else
    {
       somma += head->data;
       pos++;
       return f10(head->next,somma,pos);
    }
}

int f11(Node *head, int x)
{
    int pos = 1 , somma = 0;

    while(head != NULL)
    {
        if (pos%x == 0)
        {
            somma += head->data*pos;
        }

        pos++;
        head = head->next;
    }

    return somma;
}

int f12(Node *l1, int n, int m)
{
    sum1 = 0, sum2 = 0, pos = 0;

    while(l1 != NULL && pos < m)
    {
        if (pos < n)
        {
            sum1 += l1->data;
            pos++;
        }
        else if(pos > n+1 && pos < m)
        {
            sum2 += l2->data;
            pos++;
        }
        l1 = l1->next;
    }

    return sum1-sum2;
}

int f13(Node *l1, int x)
{
    int cnt = 0;

    if (l1 == NULL) return 0;
    if (l1->next == NULL) return 0;
    if (l1->next->next == NULL) return 0;
    else
    {
        while(l1->next->next != NULL)
        {
            if (l1->data == x && l1->data == l1->next->data && l1->next->data == l1->next->next->data)
            {
                cnt++;
            }

            l1 = l1->next;
        }
    }

    return cnt;
}

void f14(Node **headlist, int x, int n)
{
    int pos = 0;
    Node *temp = *headlist;

    while(temp != NULL)
    {
        if (temp->data == x && pos%n == 0)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            if (new_node != NULL)
            {
                new_node = x;
                new_node->next = temp->next;

                temp->next = new_node;
                pos++;
                temp = temp->next;
            }
            else
            {
                printf("ERRORE nell'allocamento del nodo \n");
                exit(1);
            }
        }
        else
        {
            pos++;
            temp = temp->next;
        }
    }
}

Node * f15(Node *l1)
{
    if (l1 == NULL) return NULL;
    if (l1->next == NULL) return NULL;
    if (l1->next->next == NULL) return NULL;
    else
    {
        Node *head = NULL, *tail = NULL, *temp = NULL;
        int i = 0;

        while(l1->next->next != NULL)
        {
            if (l1->data + l1->next->data == l1->next->next->data)
            {
                if (i == 0)
                {
                    head = (Node *)malloc(sizeof(Node));
                    if (head != NULL)
                    {
                        tail = head;

                        head->data = l1->next->next->data
                        head->next = NULL;

                        i++;
                    }
                    else
                        return NULL;
                }
                else
                {
                    temp = (Node *)malloc(sizeof(Node));
                    if (temp != NULL)
                    {
                        tail->next;
                        tail = temp;

                        tail->data = l1->next->next->data
                        tail->next = NULL;

                        i++;
                    }
                    else
                        return NULL;
                }
            }

            l1 = l1->next;
        }
    }
}

Node * f16(Node *l1, Node *l2, int n, int m)
{
    Node *head = NULL, *tail = NULL, *temp = NULL;
    int i = 1;

    while(l1 != NULL && l2 != NULL)
    {
        if (i <= n)
        {
            if (i == 1)
            {
                head = (Node *)malloc(sizeof(Node));
                if (head != NULL)
                {
                    tail = head;

                    head->data = l1->data;
                    head->next = NULL;
                }
                else
                    return NULL;
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if (temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l1->data;
                    tail->next = NULL;
                }
                else
                    return NULL;
            }
        }
        else if (i > n && i < m)
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l1->data + l2->data;
                tail->next = NULL;
            }
            else
                return NULL;
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;

                i++;
            }
            else
                return NULL;
        }

        i++;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL)
    {
        if (i <= n)
        {
            if (i == 1)
            {
                head = (Node *)malloc(sizeof(Node));
                if (head != NULL)
                {
                    tail = head;

                    head->data = l1->data;
                    head->next = NULL;
                }
                else
                    return NULL;
            }
            else
            {
                temp = (Node *)malloc(sizeof(Node));
                if (temp != NULL)
                {
                    tail->next = temp;
                    tail = temp;

                    tail->data = l1->data;
                    tail->next = NULL;
                }
                else
                    return NULL;
            }
        }
        else if (i > n && i < m)
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l1->data;
                tail->next = NULL;
            }
            else
                return NULL;
        }
        else
        {
            return head;
        }

        i++;
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        if (i <= n)
        {
            return head;
        }
        else if (i > n && i < m)
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;
            }
            else
                return NULL;
        }
        else
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                tail->next = temp;
                tail = temp;

                tail->data = l2->data;
                tail->next = NULL;
            }
            else
                return NULL;
        }

        i++;
        l2 = l2->next;
    }

    return head;
}

void f(Node **l1, Node *l2, int n)
{
    while(*l1 != NULL && l2 != NULL)
    {
        if (((*l1)->data+l2->data)%n == 0)
        {
            Node *deltesta = *l1;
            *l1 = (*l1)->next;
            l2 = l2->next;
            free(deltesta);
        }
        else
            break;
    }

    if (l2 == NULL)
    {
        while(*l1 != NULL)
        {
            if ((*l1)->data%n == 0)
            {
                Node *deltesta = *l1;
                *l1 = (*l1)->next;
                free(deltesta);
            }
            else
                break;
        }
    }
    else if (*l1 != NULL && l2 != NULL)
    {
        Node *temp = *headlist;

        while(temp != NULL && l2 != NULL)
        {
            if ((temp->data+l2->data)%n == 0)
            {
                Node *del = temp;
                temp = temp->next;
                l2 = l2->next;

                Node *prev = *l1;
                while(prev->next != del)
                    prev = prev->next;

                prev->next = temp;
                free(del);
            }
            else
            {
                temp = temp->next;
                l2 = l2->next;
            }
        }

        if (l2 == NULL)
        {
            while(temp != NULL)
            {
                if (temp->data%n == 0)
                {
                    Node *del = temp;
                    temp = temp->next;

                    Node *prev = *l1;
                    while(prev->next != del)
                        prev = prev->next;

                    prev->next = temp;
                    free(del);
                }
                else
                {
                    temp = temp->next;
                }
        }
    }

}

int f17(Node *l1)
{
    int cnt = 1, max = 1;

    if (l1 == NULL) return 0;
    if (l1->next == NULL) return 0;
    else
    {
        while(l1->next != NULL)
        {
            if (l1->data == l1->next->data)
            {
                cnt++;
                if (cnt > max)
                {
                    max = cnt;
                }
            }

            l1 = l1->next;
        }
    }

    return max;
}

int f17(Node *l1, int max)
{
    if (l1 == NULL) return 0;
    else
    {
        if (head->data > max)
        {
            max = head->data;
            1 + return f17(head->next,max);
        }
        else if (head->data == max)
        {
            1 + return f17(head->next,max);
        }
        else
            return f17(head->next,max);
    }
}

int f18(Node *head, int esito){
    
    if (head == NULL) return 0;
    else if (head->next == NULL || esito == 0) return esito;
    else
    {
        if (head->data < head->next->data)
        {
            return f18(head->next,esito);
        }
        else
        {
            esito = 0;
            return f18(head->next,esito);
        }
    }
}

int f19(Node *l1, Node *l2)
{
    if (l1 == NULL || l2 == NULL) return 0;
    else
    {
        if (l1->data == l2->data) return 1 + f19(l1->next,l2->next);
        else return 0 + f19(l1->next,l2->next);
    }
}

Node * f20(Node *l1, Node *l2)
{
    Node *temp = NULL;

    if (l1 == NULL || l2 == NULL) return NULL;
    else
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp != NULL)
        {
            temp->data = l1->data - l2->data;
            temp->next = f20(l1->next,l2->next);
            return temp;
        }
        else
            return NULL;
    }
}

Node * f21(Node *l1, Node *l2, int pos)
{
    Node *temp = NULL;

    if (l1 == NULL || l2 == NULL) return NULL;
    else
    {
        if ((l1->data + l2->data)%pos == 0)
        {
             temp = (Node *)malloc(sizeof(Node));
            if (temp != NULL)
            {
                temp->data = l1->data * l2->data;
                temp->next = f21(l1->next,l2->next);
                return temp;
            }
            else
                return NULL;
        }
        else
            f21(l1->next,l2->next)
    }
}

