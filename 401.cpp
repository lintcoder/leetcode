vector<string> readBinaryWatch(int num) {
    vector<string> res;
    const int weight[6] = {1, 2, 4, 8, 16, 32};
    if (num == 0)
        res.push_back("0:00");
    else
    {
        int beginpos = num >= 7 ? num - 6 : 0;
        int endpos = num >= 4 ? 4 : num;
        for (int i = beginpos; i <= endpos; ++i)
        {
            vector<string> hour, minute;
            combination(4, i, weight, hour);
            combination(6, num - i, weight, minute);
            int len1 = hour.size(), len2 = minute.size();
            for (int j = 0; j < len1; ++j)
            {
                for (int k = 0; k < len2; ++k)
                    res.push_back(hour[j] + ":" + minute[k]);
            }
        }
    }
    return res;
}

void combination(int total, int n, const int* weight, vector<string>& vec)
{
    if (n == 0)
    {
        if (total == 4)
            vec.push_back("0");
        else
            vec.push_back("00");
    }
    else
    {
        docombination(total, n, 0, 0, weight, vec, 0);
    }
}

void docombination(int total, int n, int pos, int subsum, const int* weight, vector<string>& vec, int ct)
{
    if (ct == n)
    {
        if (total == 4 && subsum <= 11)
        {
            if (subsum < 10)
                vec.push_back(string(1, subsum + '0'));
            else
                vec.push_back(int2str(subsum));
        }
        else if (total == 6 && subsum <= 59)
        {
            if (subsum < 10)
                vec.push_back("0" + string(1, subsum + '0'));
            else
                vec.push_back(int2str(subsum));
        }
    }
    else
    {
        for (int i = pos; i <= total - n + ct; ++i)
        {
            int tmp = subsum + weight[i];
            docombination(total, n, i + 1, tmp, weight, vec, ct + 1);
        }
    }
}

string int2str(int n)
{
    string s;
    while (n != 0)
    {
        s.insert(s.begin(), n % 10 + '0');
        n /= 10;
    }
    return s;
}
