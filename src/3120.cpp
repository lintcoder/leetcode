int numberOfSpecialChars(string word) {
        int num[26] = {0};
        int ct = 0;
        for (char c: word)
        {
            if (islower(c))
            {
                if (num[c-'a'] == 0)
                    num[c-'a'] = 1;
                if (num[c-'a'] == 2)
                {
                    num[c-'a'] = 3;
                    ++ct;
                }
            }
            else
            {
                char tmp = tolower(c);
                if (num[tmp-'a'] == 0)
                    num[tmp-'a'] = 2;
                if (num[tmp-'a'] == 1)
                {
                    num[tmp-'a'] = 3;
                    ++ct;
                }
            }
        }

        return ct;
    }