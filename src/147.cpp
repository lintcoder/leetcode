ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* node = head;
        ListNode* p = head->next;
        node->next = nullptr;
        while (p != nullptr)
        {
            ListNode* p1 = node;
            if (p->val <= p1->val)
            {
                ListNode* tmp = p->next;
                p->next = p1;
                node = p;
                p = tmp;
            }
            else
            {
                ListNode* p2 = p1;
                while (p1->next != nullptr && p1->val < p->val)
                {
                    p2 = p1;
                    p1 = p1->next;
                }
                ListNode* tmp = p->next;
                if (p1->next == nullptr)
                {
                    if (p1->val < p->val)
                    {
                        p1->next = p;
                        p->next = nullptr;
                    }
                    else
                    {
                        p2->next = p;
                        p->next = p1;
                    }
                }
                else
                {
                    p2->next = p;
                    p->next = p1;
                }
                p = tmp;
            }
        }
        
        return node;
    }