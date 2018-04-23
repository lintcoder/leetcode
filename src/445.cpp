ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a = calculateNum(l1);
        string b = calculateNum(l2);
        
        string c = stradd(a, b);
        
        ListNode* node = new ListNode(c[0]-'0');
        ListNode* root = node;
        int sz = c.size(), i = 1;
        while (i < sz)
        {
            node = new ListNode(c[i]-'0');
            node->next = root;
            root = node;
            ++i;
        }
        
        return root;
    }
    
    string calculateNum(ListNode* node)
    {
        string res;
        while (node != nullptr)
        {
            res.push_back(char(node->val + '0'));
            node = node->next;
        }
        
        return res;
    }
    
    string stradd(const string& a, const string& b)
    {
        string res;
        int len1 = a.size(), len2 = b.size();
        int i = len1 - 1, j = len2 - 1;
        int c = 0;
        
        while (i >= 0 && j >= 0)
        {
            int tmp = a[i] - '0' + b[j] - '0' + c;
            res.push_back(char(tmp%10 + '0'));
            c = tmp/10;
            --i;
            --j;
        }
        while (i >= 0)
        {
            int tmp = a[i]  - '0' + c;
            res.push_back(char(tmp%10 + '0'));
            c = tmp/10;
            --i;
        }
        while (j >= 0)
        {
            int tmp = b[j]  - '0' + c;
            res.push_back(char(tmp%10 + '0'));
            c = tmp/10;
            --j;
        }
        if (c > 0)
            res.push_back(char(c + '0'));
        
        return res;
    }