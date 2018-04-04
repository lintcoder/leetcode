int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int len1 = g.size();
    int len2 = s.size();

    int i = 0, j = 0;
    int total = 0;
    while (i < len1)
    {
        while (j < len2 && s[j] < g[i])
            ++j;
        if (j == len2)
            break;
        ++total;
        ++j;
        ++i;
    }

    return total;
}
