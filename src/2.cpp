ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
        	return l2;
        if (l2 == nullptr)
        	return l1;

        int sum = l1->val + l2->val;
        int ct = sum/10;
        ListNode* h = new ListNode(sum%10);
        ListNode* node = h;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2)
        {
        	sum = l1->val + l2->val + ct;
        	node->next = new ListNode(sum%10);
        	ct = sum/10;
        	node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
        	sum = l1->val + ct;
        	node->next = new ListNode(sum%10);
        	ct = sum/10;
        	node = node->next;
            l1 = l1->next;
        }
        while (l2)
        {
        	sum = l2->val + ct;
        	node->next = new ListNode(sum%10);
        	ct = sum/10;
        	node = node->next;
            l2 = l2->next;
        }
        if (ct != 0)
        {
        	node->next = new ListNode(ct);
            node = node->next;
        }
        node->next = nullptr;

        return h;
    }