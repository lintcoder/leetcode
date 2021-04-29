ListNode* deleteDuplicates(ListNode* head) {
       if (head == nullptr || head->next == nullptr)
           return head;
        
        ListNode* node = head;
        int refval = head->val;
        ListNode* tmp = node->next;
        bool flag = false;
        while (tmp != nullptr)
        {
            if (tmp->val == refval)
            {
                ListNode* p = tmp->next;
                delete tmp;
                tmp = p;
                flag = true;
            }
            else
            {
                if (!flag)
                {
                    head = node;
                    break;
                }
                else
                {
                    delete node;
                    node = tmp;
                    tmp = tmp->next;
                    refval = node->val;
                    flag = false;
                }
            }
        }
        
        if (tmp == nullptr)
        {
            if (flag)
            {
                delete node;
                return nullptr;
            }
            else
            {
                head = node;
                return head;
            }
        }
        
        flag = false;
        refval = tmp->val;
        ListNode* tmp2 = tmp->next;
        ListNode* lastnode = node;
        while (tmp2 != nullptr)
        {
            if (tmp2->val == refval)
            {
                ListNode* p = tmp2->next;
                tmp->next = p;
                delete tmp2;
                tmp2 = p;
                flag = true;
            }
            else
            {
                if (!flag)
                {
                    refval = tmp2->val;
                    lastnode = tmp;
                    tmp = tmp2;
                    tmp2 = tmp2->next;
                }
                else
                {
                    lastnode->next = tmp2;
                    delete tmp;
                    refval = tmp2->val;
                    tmp = tmp2;
                    tmp2 = tmp2->next;
                    flag = false;
                }
            }
        }
        
        if (flag)
        {
            lastnode->next = nullptr;
            delete tmp;
        }
        
        return head;
    }