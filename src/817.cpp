int numComponents(ListNode* head, vector<int>& G) {
        int arr[10000] = {0};
        int len = G.size();
        for (int i = 0; i < len; ++i)
        	arr[G[i]] = 1;

        ListNode* h = head;
        int ct = 0;
        while (h != nullptr && arr[h->val] == 0)
        	h = h->next;
        if (h == nullptr)
        	return ct;
        bool flag = true;
        h = h->next;
        while (h != nullptr)
        {
        	if (arr[h->val] == 0 && flag)
        	{
        		flag = false;
        		++ct;
        	}
        	else if (arr[h->val] == 1 && !flag)
        	{
        		flag = true;
        	}
        	h = h->next;
        }
        if (flag)
        	++ct;

        return ct;
    }