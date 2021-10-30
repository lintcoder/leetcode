    bool areNumbersAscending(string s) {
        int len = s.size();
        int index = 0;
        int pos = s.find(' ', index);
        int lastnum = 0;
        while (pos != string::npos)
        {
            if (isdigit(s[index]))
            {
                int sum = 0;
                for (int i = index; i < pos; ++i)
                    sum = 10*sum + (s[i]-'0');
                if (sum <= lastnum)
                    return false;
                else
                    lastnum = sum;
            }
            index = pos+1;
            pos = s.find(' ', index);
        }
        
        if (isdigit(s[index]))
        {
            int sum = 0;
            for (int i = index; i < len; ++i)
                sum = 10*sum + (s[i]-'0');
            if (sum <= lastnum)
                return false;
        }
        
        return true;
    }