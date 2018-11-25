bool isValid(string s) {
        int sz = s.size();
        if (sz % 2 == 1)
            return false;
        stack<int> stk;
        for (int i = 0; i != sz; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if (stk.empty() || ((s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{')))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }