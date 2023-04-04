int vowelStrings(vector<string>& words, int left, int right) {
        int ct = 0;
        for (int i = left; i <= right; ++i)
        {
            char s = words[i][0], e = *words[i].rbegin();
            if ((s == 'a' || s == 'e' || s == 'i' ||
                s == 'o' || s == 'u') && (e == 'a' || e == 'e' ||
                e == 'i' || e == 'o' || e == 'u'))
                ++ct;
        }

        return ct;
    }