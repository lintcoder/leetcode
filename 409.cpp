int longestPalindrome(string s) {
    int alpha[52] = {0};
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        if (islower(s[i]))
            alpha[s[i] - 'a']++;
        else
            alpha[s[i] - 'A' + 26]++;
    }
    int sum = 0;
    int flag = 0;
    for (int i = 0; i < 52; ++i)
    {
        sum += alpha[i] / 2;
        if (!flag && alpha[i] % 2 == 1)
            flag = 1;
    }
    return sum * 2 + flag;
}
