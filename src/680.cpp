bool validPalindrome(string s) {
        int len = s.size();
        if (len <= 2)
            return true;
        
        return search(s, 0, len-1, false);
    }
    
    bool search(const string& s, int p, int q, bool flag)
    {
        if (p >= q)
            return true;
        if (flag)
        {
            while (p < q)
            {
                if (s[p] != s[q])
                    return false;
                else
                {
                    ++p;
                    --q;
                }
            }
            
            return true;
        }
        else
        {
            if (s[p] == s[q])
            {
                return search(s, p+1, q-1, false) || search(s, p+1, q, true)
                    || search(s, p, q-1, true);
            }
            else
                return search(s, p+1, q, true) || search(s, p, q-1, true);
        }
    }