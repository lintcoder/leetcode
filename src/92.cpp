ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr || m >= n)
                return head;

        ListNode* h = nullptr;
        ListNode* prev = nullptr;
        ListNode* first = nullptr;
        int i = 0;
        if (m == 1)
        {
                first = head;
        }
        else
        {
                h = head;
                prev = head;
                i = 1;
                while (i < m-1)
                {
                        prev = prev->next;
                        ++i;
                }
                first = prev->next;
        }

        ListNode* last = first;
        ListNode* node = first->next;
        ++i;
        while (i < n)
        {
        	ListNode* t = node->next;
        	node->next = first;
        	first = node;
        	node = t;
        	++i;
        }

        if (prev == nullptr)
        	h = first;
        else
        	prev->next = first;
        last->next = node;

        return h;
    }