char findTheDifference(string s, string t) {
    int alpha1[26] = {0};
    int alpha2[26] = {0};

    int len1 = s.size();
    int len2 = t.size();
    int i = 0;
    for (i = 0; i < len1; ++i)
        alpha1[s[i] - 'a']++;
    for (i = 0; i < len2; ++i)
        alpha2[t[i] - 'a']++;
    for (i = 0; i < 26; ++i)
        if (alpha1[i] < alpha2[i])
            break;
    return i + 'a';
}
