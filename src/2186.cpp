int minSteps(string s, string t) {
        int num1[26] = {0};
        int num2[26] = {0};
        int len1 = s.size(), len2 = t.size();
        for (int i = 0; i < len1; ++i)
            num1[s[i]-'a']++;
        for (int i = 0; i < len2; ++i)
            num2[t[i]-'a']++;
        
        int ct = 0;
        for (int i = 0; i < 26; ++i)
            ct += abs(num1[i]-num2[i]);
        
        return ct;
    }