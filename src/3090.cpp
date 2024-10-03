int maximumLengthSubstring(string s) {
        size_t len {s.size()};
        size_t i = 0, j = 1, maxlength = 0;
        int arr[26] = {0};

        arr[s[i]-'a']++;

        while (j < len)
        {
            if (arr[s[j]-'a'] == 2)
            {
                if (j-i > maxlength)
                    maxlength = j-i;
                arr[s[i]-'a']--;
                ++i;
            }
            else
            {
                arr[s[j]-'a']++;
                ++j;
            }
        }
        if (j-i > maxlength)
            maxlength = j-i;

        return maxlength;
    }