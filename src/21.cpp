ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* h = l1->val < l2->val ? l1 : l2;
        ListNode* p = h;
        ListNode* q = l1, *t = l2;
        if (l1->val < l2->val)
            q = q->next;
        else
            t = t->next;
        while (q != NULL && t != NULL)
        {
            if (q->val < t->val)
            {
                p->next = q;
                p = q;
                q = q->next;
            }
            else
            {
                p->next = t;
                p = t;
                t = t->next;
            }
        }
        if (q != NULL)
            p->next = q;
        else
            p->next = t;
        return h;
    }