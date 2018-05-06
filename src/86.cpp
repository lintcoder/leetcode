ListNode* partition(ListNode* head, int x) {
	    if (head == nullptr || head->next == nullptr)
	    	return head;

        ListNode* less = nullptr, *nodel = nullptr;
        ListNode* more = nullptr, *noder = nullptr;
        ListNode* h = head;
        while (h != nullptr)
        {
        	if (h->val < x)
        	{
        		if (less == nullptr)
        		{
        			less = h;
        			nodel = h;
        		}
        		else
        		{
        			nodel->next = h;
        			nodel = h;
        		}
        	}
        	else
        	{
        		if (more == nullptr)
        		{
        			more = h;
        			noder = h;
        		}
        		else
        		{
        			noder->next = h;
        			noder = h;
        		}
        	}
        	h = h->next;
        }
        if (less == nullptr)
        {
            noder->next = nullptr;
            less = more;
        }
        else if (more == nullptr)
        {
            nodel->next = nullptr;
        }
        else
        {
            nodel->next = more;
            noder->next = nullptr;
        }

        return less;
    }