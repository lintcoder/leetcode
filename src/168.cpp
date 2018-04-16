string convertToTitle(int n) {
        char digit[26];
        digit[0] = 'Z';
        for (int i = 1; i < 26; ++i)
            digit[i] = 'A' + i - 1;
        string str;
        while (n > 0)
        {
            int pos = n % 26;
            str.push_back(digit[pos]);
            if (pos == 0)
                n = n / 26 - 1;
            else
                n = n / 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }