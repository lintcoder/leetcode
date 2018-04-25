ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        	return head;

        ListNode* hodd = head;
        ListNode* heven = head->next;
        ListNode* p = hodd, *q = heven;

        while (q != nullptr && q->next != nullptr)
        {
        	p->next = q->next;
        	if (q->next == nullptr)
        		break;	
        	else
        	{
        		p = q->next;
        		q->next = p->next;
        		q = p->next;
        	}
        }

        p->next = heven;
        return hodd;
    }