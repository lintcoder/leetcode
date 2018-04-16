ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode* p = headA, *q = headB;
        while (p != NULL)
        {
            p = p->next;
            len1++;
        }
        while (q != NULL)
        {
            q = q->next;
            len2++;
        }
        p = headA;
        q = headB;
        while (len1 < len2)
        {
            q = q->next;
            len2--;
        }
        while (len1 > len2)
        {
            p = p->next;
            len1--;
        }
        while (p != NULL && q != NULL)
        {
            if (p == q)
                return p;
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }