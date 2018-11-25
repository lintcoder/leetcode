string countAndSay(int n) {
        if (n <= 0)
        return "";
        deque<int> dq;
        dq.push_back(1);
    
        int i = 1;
        while (i < n)
        {
            int len = dq.size();
            int ct = 1, num = dq.at(0);
            for (int j = 1; j < len; ++j)
            {
                int val = dq.at(j);
                if (val == num)
                    ++ct;
                else
                {
                    dq.push_back(ct);
                    dq.push_back(num);
                    num = val; 
                    ct = 1;
                }
            }
            dq.push_back(ct);
            dq.push_back(num);
            dq.erase(dq.begin(), dq.begin() + len);
            ++i;
        }
    
        int sz = dq.size();
        string res(sz + 1, '\0');
        for (int j = 0; j < sz; ++j)
            res[j] = dq.at(j) + '0';
    
        return res;
    }