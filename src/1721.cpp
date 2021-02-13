ListNode* swapNodes(ListNode* head, int k) {
        int ct = 0;
        ListNode* p = head;
        while (p != nullptr)
        {
            p = p->next;
            ++ct;
        }
        
        int i = 0, j = ct - k + 1;
        int m = 0;
        if (k == j)
            return head;
        
        p = head;
        ListNode* nodearr[2];
        while (p != nullptr)
        {
            ++i;
            if (i == k || i == j)
            {
                nodearr[m++] = p;
                if (m == 2)
                    break;
            }
            p = p->next;
        }
        
        int tmp = nodearr[0]->val;
        nodearr[0]->val = nodearr[1]->val;
        nodearr[1]->val = tmp;
        
        return head;
    }