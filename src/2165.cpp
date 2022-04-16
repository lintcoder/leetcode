long long smallestNumber(long long num) {
        if (num == 0)
            return 0;
        else if (num < 0)
        {
            num = -num;
            string s = to_string(num);
            sort(s.begin(), s.end(), greater<char>());
            return -1*stoll(s, nullptr);
        }
        else
        {
            string s = to_string(num);
            sort(s.begin(), s.end());
            int len = s.size();
            int i = 0;
            for (i = 0; i < len; ++i)
            {
                if(s[i] != '0')
                    break;
            }
            if (i != len)
            {
                char c = s[i];
                for (; i >= 1; --i)
                {
                    s[i] = s[i-1];
                }
                s[0] = c;
            }

            return stoll(s, nullptr);
        }
    }