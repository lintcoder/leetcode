string reverseWords(string s) {
        size_t len = s.size();
        if (len == 0)
            return s;
        size_t i = 0;
        size_t pos = s.find(' ', i);
        while (pos != string::npos)
        {
            reverse_str(s, i, pos - 1);
            i = pos + 1;
            pos = s.find(' ', i);
        }
        reverse_str(s, i, len - 1);
        return s;
    }
    
    void reverse_str(string& s, size_t start, size_t end)
    {
        size_t lim = (start + end)/2;
        for (size_t i = start; i <= lim; ++i)
        {
            swap(s[i], s[end--]);
        }
    }