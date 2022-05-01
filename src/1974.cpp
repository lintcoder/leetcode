int minTimeToType(string word) {
        int len = word.size();
        int cur = 'a';
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            int tmp = abs(word[i]-cur);
            ct += tmp < 26-tmp ? tmp : 26-tmp;
            cur = word[i];
        }
        
        return ct + len;
    }