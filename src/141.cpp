bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        while (p != NULL)
        {
            p = p->next;
            if (p == NULL)
                return false;
            if (p == q || p->next == q)
                return true;
            p = p->next;
            q = q->next;
            if (p == q)
                return true;
        }
        
        return false;
    }