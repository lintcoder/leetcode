vector<string> findRelativeRanks(vector<int>& nums) {
    vector<string> res;
    int len = nums.size();
    if (len == 0)
        return res;
    res.resize(len);
    struct Elem
    {
        int val;
        int pos;
        Elem(int v, int p):val(v), pos(p){}
    };
    vector<Elem> vec;
    for (int i = 0; i < len; ++i)
        vec.push_back(Elem(nums[i], i));
    auto cmp = [=](Elem& a, Elem& b) { return a.val > b.val;};
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < len; ++i)
    {
        if (i == 0)
            res[vec[i].pos] = "Gold Medal";
        else if (i == 1)
            res[vec[i].pos] = "Silver Medal";
        else if (i == 2)
            res[vec[i].pos] = "Bronze Medal";
        else
            res[vec[i].pos] = num2str(i + 1);
    }

    return res;
}

string num2str(int num)
{
    string str;
    while (num != 0)
    {
        str.push_back(char(num % 10 + '0'));
        num /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
