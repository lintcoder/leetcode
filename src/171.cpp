int titleToNumber(string s) {
    int len = s.size();
    int sum = 0;
    for (int i = 0; i < len; ++i)
        sum = sum * 26 + s[i] - 'A' + 1;
    return sum;
}
