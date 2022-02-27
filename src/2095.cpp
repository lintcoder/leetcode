ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        
        int ct = 0;
        ListNode* node = head;
        while (node != nullptr)
        {
            ++ct;
            node = node->next;
        }
        
        int n = ct/2;
        int i = 0;
        ListNode* h = head, *cur = h;
        node = h->next;
        while (i != n-1)
        {
            cur = node;
            node = node->next;
            ++i;
        }
        
        cur->next = node->next;
        delete node;
        return h;
    }