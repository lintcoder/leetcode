ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head->next;
        delete head;
        
        ListNode* h = p;
        ListNode* cur = h;
        ListNode* node = p->next;
        while (node != nullptr)
        {
            ListNode* tmp = node;
            node = node->next;
            if (tmp->val != 0)
            {
                cur->val += tmp->val;
            }
            else
            {
                cur->next = node;
                cur = node;
                if (node == nullptr)
                    break;
                node = node->next;
            }
            delete tmp;
        }
        
        return h;
    }