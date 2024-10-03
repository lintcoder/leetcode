string getEncryptedString(string s, int k) {
        int len = s.size();
        if (k%len == 0)
            return s;
        else
        {
            int p = k%len;
            return s.substr(p) + s.substr(0, p);
        }
    }