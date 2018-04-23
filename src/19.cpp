ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0)
            return head;
        vector<ListNode*> vec;
        ListNode* p = head;
        int len = 0;
        while (p != NULL)
        {
            vec.push_back(p);
            p = p->next;
            len++;
        }
        if (n == len)
        {
            head = vec[0]->next;
            delete vec[0];
        }
        else
        {
            vec[len - n - 1]->next = vec[len - n]->next;
            delete vec[len - n];
        }
        
        return head;
    }