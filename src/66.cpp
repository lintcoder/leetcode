vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        vector<int> res(sz + 1, 0);
        int cnt = 1;
        for (int i = sz - 1; i >= 0; --i)
        {
            if (cnt != 0)
            {
                int sum = digits[i] + cnt;
                res[i + 1] = sum % 10;
                cnt =sum / 10;
            }
            else
                res[i + 1] = digits[i];
        }
        res[0] = cnt;
        if (res[0] != 0)
            return res;
        else
            return vector<int>(res.begin() + 1, res.end());
    }