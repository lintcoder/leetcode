ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == head)
        	return head;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next;
        if (fast == nullptr)
            return nullptr;
        fast = fast->next;
        slow = slow->next;
        while (fast != nullptr && slow != nullptr)
        {
        	if (fast != slow)
        	{
        		fast = fast->next;
        		slow = slow->next;
        		if (fast == nullptr)
        			return nullptr;
        		else
        			fast = fast->next;
        	}
        	else
        		break;
        }
        if (fast == nullptr)
        	return nullptr;
        slow = head;
        while (slow != fast)
        {
        	slow = slow->next;
        	fast = fast->next;
        }
        return slow;
    }