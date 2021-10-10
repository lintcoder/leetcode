int calculate(string s) {
        int len = s.size();
        int i = 0;
        deque<char> dq;
        
        int n = 0;
        while (i < len)
        {
            if (s[i] != ' ')
            {
                dq.push_back(s[i]);
                ++n;
            }
            ++i;
        }
        
        i = 0;
        int v = 0;
        deque<int> number;
        deque<char> op;
        bool flag = false;
        while (i < n)
        {
            if (dq[i] >= '0' && dq[i] <= '9')
            {
                v = v*10 + (dq[i]-'0');
                ++i;
                flag = true;
            }
            else
            {
                if (dq[i] == '+' || dq[i] == '-')
                {
                    number.push_back(v);
                    op.push_back(dq[i]);
                    v = 0;
                    ++i;
                    flag = false;
                }
                else
                {
                    char c = dq[i];
                    ++i;
                    int v2 = 0;
                    while (i < n && dq[i] >= '0' && dq[i] <= '9')
                    {
                        v2 = v2*10 + (dq[i]-'0');
                        ++i;
                    }
                    if (c == '*')
                        v *= v2;
                    else
                        v /= v2;
                    flag = true;
                }
            }
        }
        if (flag)
            number.push_back(v);
        
        int k = op.size();
        int j = 0;
        int sum = number[0];
        while (j < k)
        {
            if (op[j] == '+')
                sum += number[j+1];
            else
                sum -= number[j+1];
            ++j;
        }
        
        return sum;
    }