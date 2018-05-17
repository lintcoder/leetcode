string toHex(int num) {
        if (num == 0)
            return "0";
        bitset<32> bs(num);
        int sum = 0;
        bool flag = false;
        string res;
        for (int i = 1; i <= 32; ++i)
        {
            sum = sum * 2 + bs[32 - i];
            if (i % 4 == 0)
            {
                if (sum != 0)
                {
                    char c = sum <= 9 ? sum + '0' : sum - 10 + 'a';
                    res.push_back(c);
                    flag = true;
                }
                else
                {
                    if (flag)
                        res.push_back('0');
                }
                sum = 0;
            }
        }
        return res;
    }