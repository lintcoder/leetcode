vector<ListNode*> splitListToParts(ListNode* root, int k) {
     vector<ListNode*> res;
     if (root == nullptr)
     {
         res.insert(res.end(), k, nullptr);
         return res;
     }

     int len = 0;
     ListNode* h = root;
     while (h != nullptr)
     {
     	++len;
     	h = h->next;
     }
     int each = len/k;
     int remain = len%k;
     int i = 0;

     h = root;
     while (i < k)
     {
     	if (i < remain)
     	{
     		ListNode* node = h;
     		ListNode* pre = h;
     		for (int j = 0; j < each+1; ++j)
     		{
     			pre = node;
     			node = node->next;
     		}
     		pre->next = nullptr;
     		res.push_back(h);
     		h = node;
     	}
     	else
     	{
     		if (h == nullptr)
     		{
     			res.push_back(nullptr);
     		}
     		else
     		{
     			ListNode* node = h;
     			ListNode* pre = h;
     			for (int j = 0; j < each; ++j)
     			{
     				pre = node;
     				node = node->next;
     			}
     			pre->next = nullptr;
     			res.push_back(h);
     			h = node;
     		}
     	}
     	++i;
     }
     return res;   
    }