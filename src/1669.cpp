ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1, *q = list2;
        ListNode* pr = list1;
        int i = 0;
        while (i < a-1)
        {
            p = p->next;
            pr = p;
            ++i;
        }
        while (i < b)
        {
            pr = pr->next;
            ++i;
        }
        
        while (q->next != nullptr)
            q = q->next;
        
        p->next = list2;
        q->next = pr->next;
        pr->next = nullptr;
        
        return list1;
    }