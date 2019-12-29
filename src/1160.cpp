int countCharacters(vector<string>& words, string chars) {
        int sz = words.size();
        int len = chars.size();
        
        char num[26] = {0};
        for (int i = 0; i < len; ++i)
            num[chars[i]-'a']++;
        
        char tmp[26];
        int sum = 0;
        for (int i = 0; i < sz; ++i)
        {
            memset(tmp, 0, 26*sizeof(char));
            int wsz = words[i].size();
            int j = 0;
            for (j = 0; j < wsz; ++j)
            {
                int p = words[i][j]-'a';
                tmp[p]++;
                if (tmp[p] > num[p])
                    break;
            }
            if (j == wsz)
                sum += wsz;
        }
        
        return sum;
    }