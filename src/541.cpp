string reverseStr(string s, int k) {
        int len = s.size();
        int num = len / (2 * k);
        for (int i = 0; i < num; ++i)
            reverse(s.begin() + i * 2 * k, s.begin() + (2 * i + 1) * k);
        int remain = len % (2 * k);
        if (remain >= k)
            reverse(s.begin() + num * 2 * k, s.begin() + (num * 2 + 1) * k);
        else
            reverse(s.begin() + num * 2 * k, s.end());
        
        return s;
    }