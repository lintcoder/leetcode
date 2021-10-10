ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        
        int sz = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            ++sz;
        }
        
        int q = sz/k;
        int r = sz - q*k;
        int i = 1, n = 0;
        ListNode* h = nullptr;
        ListNode* tail = nullptr;
        ListNode* ps = head, *pds = head, *pde = head;
        ps = ps->next;
        while (i < k)
        {
            ListNode* pp = ps->next;
            ps->next = pds;
            pds = ps;
            ps = pp;
            ++i;
        }
        h = pds;
        ++n;
        tail = pde;
        
        while (n < q)
        {
            pds = ps;
            pde = ps;
            i = 1;
            ps = ps->next;
            while (i < k)
            {
                ListNode* pp = ps->next;
                ps->next = pds;
                pds = ps;
                ps = pp;
                ++i;
            }
            tail->next = pds;
            tail = pde;
            ++n;
        }
        
        tail->next = ps;
        return h;
    }