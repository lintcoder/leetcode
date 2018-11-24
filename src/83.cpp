ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* h = head;
        int key = h->val;
        ListNode* p = h->next;
        ListNode* q = h;
        while (p != NULL)
        {
            while (p != NULL && p->val == key)
            {
                ListNode* k = p->next;
                delete p;
                p = k;
            }
            q->next = p;
            q = p;
            if (p != NULL)
            {
                key = p->val;
                p = p->next;
            }
        }
        
        return h;
    }