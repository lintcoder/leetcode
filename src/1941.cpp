bool areOccurrencesEqual(string s) {
        int counts[26] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            ++counts[s[i]-'a'];
        }
        
        int num = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] > 0)
            {
                if (num == 0)
                    num = counts[i];
                else if (counts[i] != num)
                    return false;
            }
        }
        
        return true;
    }