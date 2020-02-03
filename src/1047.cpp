string removeDuplicates(string S) {
        int len = S.size();
        if (len == 1)
            return S;
        string res;
        stack<char> stk;
        for (int i = 0; i < len; ++i)
        {
            if (stk.empty())
                stk.push(S[i]);
            else
            {
                if (stk.top() == S[i])
                    stk.pop();
                else
                    stk.push(S[i]);
            }
        }
        
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }