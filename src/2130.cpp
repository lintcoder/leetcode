int pairSum(ListNode* head) {
        vector<int> num(1e5, 0);
        int n = 0;
        while (head != nullptr)
        {
            num[n++] = head->val;
            head = head->next;
        }
        
        int lim = n/2-1;
        int maxval = 0;
        for (int i = 0; i <= lim; ++i)
        {
            int tmp = num[i] + num[n-1-i];
            if (tmp > maxval)
                maxval = tmp;
        }
        
        return maxval;
    }