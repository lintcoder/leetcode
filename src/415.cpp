string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int sum = 0, ct = 0;
        int i = len1 - 1, j = len2 - 1;
        string res;
        while (i >= 0 && j >= 0)
        {
            sum = num1[i] - '0' + num2[j] - '0' + ct;
            res.push_back(char(sum % 10 + '0'));
            ct = sum / 10;
            --i;
            --j;
        }
        if (i >= 0)
        {
            while (i >= 0)
            {
                sum = num1[i] - '0' + ct;
                res.push_back(char(sum % 10 + '0'));
                ct = sum / 10;
                --i;
            }
            if (ct > 0)
            {
                res.push_back(char(ct + '0'));
                ct = 0;
            }
        }
        if (j >= 0)
        {
            while (j >= 0)
            {
                sum = num2[j] - '0' + ct;
                res.push_back(char(sum % 10 + '0'));
                ct = sum / 10;
                --j;
            }
            if (ct > 0)
            {
                res.push_back(char(ct + '0'));
                ct = 0;
            }
        }
        if (ct > 0)
            res.push_back(char(ct + '0'));
        reverse(res.begin(), res.end());
        return res;
    }