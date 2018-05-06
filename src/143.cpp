void reorderList(ListNode* head) {
     if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
     return;

     ListNode* h = head;
     int i = 0;
     while (h != nullptr)
     {
     	h = h->next;
     	++i;
     }
     int n = i%2 == 0 ? i/2 : i/2+1;
     h = head;
     ListNode* fronthalf = h;
     ListNode* node = h;
     while (n-- > 1)
     	node = node->next;
     ListNode* s = node->next;
     node->next = nullptr;

     node = s;
     ListNode* backhalf = node;
     node = node->next;
     backhalf->next = nullptr;
     s = nullptr;
     while (node != nullptr)
     {
     	s = node->next;
     	node->next = backhalf;
     	backhalf = node;
     	node = s;
     }
     head = fronthalf;
     node = fronthalf;
     s = backhalf;
     while (node != nullptr && s != nullptr)
     {
     	ListNode* tmp = node->next;
     	node->next = s;
     	node = tmp;
     	ListNode* tmp2 = s->next;
     	s->next = tmp;
     	s = tmp2;
     }
    }