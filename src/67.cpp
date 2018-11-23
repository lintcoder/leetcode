string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        
        string res(len1 > len2 ? len1 + 1 : len2 + 1, '0');
        int i = len1 - 1, j = len2 - 1;
        int ct = 0, k = res.size() - 1;
        while (i >= 0 && j >= 0)
        {
            int sum = a[i] - '0' + b[j] - '0' + ct;
            res[k] = sum % 2 + '0';
            --k;
            --i;
            --j;
            ct = sum >> 1 ? 1 : 0;
        }
        while (i >= 0)
        {
            int sum = a[i] - '0' + ct;
            res[k] = sum % 2 + '0';
            --k;
            --i;
            ct = sum >> 1 ? 1 : 0;
        }
        while (j >= 0)
        {
            int sum = b[j] - '0' + ct;
            res[k] = sum % 2 + '0';
            --k;
            --j;
            ct = sum >> 1 ? 1 : 0;
        }
        if (ct > 0)
            res[k] = ct + '0';
        if (res[0] == '0')
            return string(res.begin() + 1, res.end());
        else
            return res;
    }