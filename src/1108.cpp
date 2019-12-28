string defangIPaddr(string address) {
        int sz = address.size();
        string res(sz+6, ' ');
        int i = 0, j = 0;
        while (i < sz)
        {
            if (address[i] != '.')
                res[j++] = address[i];
            else
            {
                res[j] = '[';
                res[j+1] = '.';
                res[j+2] = ']';
                j += 3;
            }
            ++i;
        }
        
        return res;
    }