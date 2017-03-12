vector<string> findWords(vector<string>& words) {
    const int pos[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2,
        2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    vector<string> res;
    int len = words.size();
    for (int i = 0; i < len; ++i)
    {
        int p = pos[tolower(words[i][0]) - 'a'];
        int sz = words[i].size();
        int j;
        for (j = 1; j < sz; ++j)
            if (pos[tolower(words[i][j]) - 'a'] != p)
                break;
        if (j == sz)
            res.push_back(words[i]);
    }
    return res;
}
