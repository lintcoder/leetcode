ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        
        int ct = 0;
        ListNode* p = head;
        while (p != nullptr)
        {
            ++ct;
            p = p->next;
        }
        
        int lim = 2*ct;
        int n = sqrt(lim);
        int tmp = n*(n+1);
        int r = 0;
        if (tmp == lim)
            ;
        else if (tmp < lim)
            r = ct-tmp/2;
        else
        {
            r = ct-n*(n-1)/2;
            --n;
        }
        
        ListNode* pre = head;
        ListNode* post = pre->next;
        ListNode* cur = post->next;
        int i = 2;
        bool flag = true;
        while (i <= n)
        {
            if (flag)
            {
                p = post;
                for (int j = 1; j < i; ++j)
                {
                    pre->next = cur;
                    ListNode* tmp = cur->next;
                    cur->next = p;
                    p = cur;
                    cur = tmp;
                }
                post->next = cur;
            }
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    pre = cur;
                    cur = cur->next;
                }
                post = cur;
                if (cur != nullptr)
                    cur = cur->next;
            }
            flag = !flag;
            ++i;
        }
        
        if (r > 0)
        {
            if (!flag)
            {
                pre = post;
                post = post->next;
                if (cur != nullptr)
                    cur = cur->next;
            }
            if (r%2 == 0)
            {
                p = post;
                for (int j = 1; j < r; ++j)
                {
                    pre->next = cur;
                    ListNode* tmp = cur->next;
                    cur->next = p;
                    p = cur;
                    cur = tmp;
                }
                post->next = cur;
            }
        }
        
        return head;
    }