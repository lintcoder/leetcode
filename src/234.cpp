bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        int num = 0;
        while (p != NULL)
        {
            p = p->next;
            num++;
        }
        int lim = num / 2;
        int n = 0;
        if (lim > 0)
        {
            ListNode* h = head;
            ListNode* q = h->next;
            h->next = NULL;
            n++;
            while (n < lim)
            {
                p = q->next;
                q->next = h;
                h = q;
                q = p;
                n++;
            }
            if (num % 2 == 1)
                q = q->next;
            while (h != NULL && q != NULL)
            {
                if (h->val != q->val)
                    return false;
                h = h->next;
                q = q->next;
            }
        }
        return true;
    }