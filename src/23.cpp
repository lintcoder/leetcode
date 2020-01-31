ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        int len = lists.size();
        if (len == 0)
            return head;
        if (len == 1)
            return lists[0];
        
        struct cmp
        {
            bool operator()(ListNode* a, ListNode* b)
            {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < len; ++i)
            pq.push(lists[i]);
        head = pq.top();
        pq.pop();
        if (head->next != nullptr)
            pq.push(head->next);
        ListNode* node = head;
        while (!pq.empty())
        {
            ListNode* tmp = pq.top();
            pq.pop();
            if (tmp->next != nullptr)
                pq.push(tmp->next);
            node->next = tmp;
            node = tmp;
        }
        node->next = nullptr;
        
        return head;
    }