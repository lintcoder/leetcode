string truncateSentence(string s, int k) {
        int i = 0;
        int index = 0;
        int pos = 0;
        while (i < k)
        {
            pos = s.find(' ', index);
            ++i;
            index = pos+1;
        }
        
        return s.substr(0, pos);
    }