int firstUniqChar(string s) {
    int alpha[26] = {0};
    int len = s.size();
    for (int i = 0; i < len; ++i)
        alpha[s[i] - 'a']++;
    for (int i = 0; i < len; ++i)
        if (alpha[s[i] - 'a'] == 1)
            return i;
    return -1;
}
