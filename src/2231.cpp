int largestInteger(int num) {
        string s = to_string(num);
        int len = s.size();
        int odd[10] = {0};
        int even[10] = {0};
        int nodd = 0, neven = 0;
        for (int i = 0; i < len; ++i)
        {
            if ((s[i]-'0')%2 == 0)
                even[neven++] = i;
            else
                odd[nodd++] = i;
        }
        
        for (int i = 0; i < len; ++i)
        {
            if ((s[i]-'0')%2 == 0)
            {
                for (int j = 0; j < neven; ++j)
                {
                    if (i < even[j] && s[i] < s[even[j]])
                        swap(s[i], s[even[j]]);
                }
            }
            else
            {
                for (int j = 0; j < nodd; ++j)
                    if (i < odd[j] && s[i] < s[odd[j]])
                        swap(s[i], s[odd[j]]);
            }
        }
        
        return stoi(s);
    }