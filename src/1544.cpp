string makeGood(string s) {
        int len = s.size();
        string res(len, ' ');
        int i = 0, j = 0;
        res[j] = s[i];
        ++i;
        ++j;
        while (i < len)
        {
            if (j == 0)
            {
                res[j++] = s[i++];
            }
            else if ((islower(res[j-1]) && isupper(s[i]) && res[j-1] == tolower(s[i]))
                || (isupper(res[j-1]) && islower(s[i]) && res[j-1] == toupper(s[i])))
            {
                --j;
                ++i;
            }
            else
            {
                res[j++] = s[i++];
            }      
        }
        
        return res.substr(0, j);
    }