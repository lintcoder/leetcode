vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res(2, -1);
    int len = numbers.size();
    for (int i = 0; i < len; ++i)
    {
        int index = 0;
        if (BSearch(numbers, i + 1, len - 1, target - numbers[i], index))
        {
            res[0] = i + 1;
            res[1] = index + 1;
            break;
        }
    }
    return res;
}

bool BSearch(vector<int>& numbers, int p, int q, int val, int& index)
{
    while (p <= q)
    {
        int mid = (p + q) / 2;
        if (numbers[mid] == val)
        {
            index = mid;
            return true;
        }
        else if (numbers[mid] < val)
            p = mid + 1;
        else
            q = mid - 1;
    }
    return false;
}
