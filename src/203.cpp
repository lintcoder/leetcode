ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head, *q;
        while (p != NULL && p->val == val)
        {
            q = p->next;
            delete p;
            p = q;
        }
        if (p == NULL)
            return NULL;
        head = p;
        q = p->next;
        while (q != NULL)
        {
            while (q != NULL && q->val == val)
            {
                ListNode* k = q->next;
                delete q;
                q = k;
            }
            if (q != NULL)
            {
                p->next = q;
                p = q;
                q = q->next;
            }
            else
                p->next = q;
        }
        
        return head;
    }