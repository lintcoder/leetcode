bool isPalindrome(string s) {
    int len = s.size();
    int i = 0, j = len - 1;
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
            ++i;
        if (i == j)
            return true;
        while (i < j && !isalnum(s[j]))
            --j;
        if (i == j)
            return true;
        if (!(s[i] == s[j] || tolower(s[i]) == tolower(s[j])))
            return false;
        else
        {
            ++i;
            --j;
        }
    }
    return true;
}
