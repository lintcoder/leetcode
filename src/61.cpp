ListNode* rotateRight(ListNode* head, int k) {
     if (head == nullptr || head->next == nullptr)
     return head;

     ListNode* h = head;
     int len = 0;
     while (h != nullptr)
     {
     	++len;
     	h = h->next;
     }
     int n = k % len;
     if (n == 0)
     	return head;
     h = head;
     int i = 0, limit = len - n;
     ListNode* node = nullptr;
     while (i < limit)
     {
     	node = h;
     	h = h->next;
     	++i;
     }
     node->next = nullptr;
     node = h;
     while (node->next != nullptr)
     	node = node->next;
     node->next = head;
     return h;
    }