string convertToBase7(int num) {
    if (num == 0)
        return "0";
    string res;
    bool flag = true;
    if (num < 0)
    {
        flag = false;
        num = -num;
    }
    while (num != 0)
    {
        res.push_back(char(num % 7 + '0'));
        num /= 7;
    }
    reverse(res.begin(), res.end());
    if (flag == false)
        res = "-" + res;

    return res;
}
