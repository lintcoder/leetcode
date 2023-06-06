int minimizedStringLength(string s) {
        char arr[26] = {0};
        int len = s.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            arr[s[i]-'a']++;
            if (arr[s[i]-'a'] == 1)
                ++ct;
        }

        return ct;
    }