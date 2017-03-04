bool canConstruct(string ransomNote, string magazine) {
    int alpha1[26] = {0};
    int alpha2[26] = {0};
    int len1 = ransomNote.size();
    int len2 = magazine.size();
    if (len1 > len2)
        return false;
    for (int i = 0; i < len1; ++i)
        alpha1[ransomNote[i] - 'a']++;
    for (int i = 0; i < len2; ++i)
        alpha2[magazine[i] - 'a']++;
    for (int i = 0; i < 26; ++i)
        if (alpha1[i] > alpha2[i])
            return false;

    return true;
}
