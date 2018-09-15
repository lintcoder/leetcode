ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        	return head;

        int len = 0;
        ListNode* node = head;
        while (node != nullptr)
        {
        	node = node->next;
        	++len;
        }
        int pos = len/2;
        int i = 0;
        node = head;
        while (i != pos)
        {
        	node = node->next;
        	++i;
        }

        return node;
    }