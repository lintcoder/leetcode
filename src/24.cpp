ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* h = q;
        
        p->next = q->next;
        q->next = p;
        ListNode* k = p->next;
        int n = 1;
        while (k != NULL)
        {
            if (n == 1)
            {
                q = p;
                p = k;
                k = k->next;
            }
            else
            {
                p->next = k->next;
                q->next = k;
                k->next = p;
                k = p->next;
            }
            n = 1 - n;
        }
        
        return h;
    }