int countPrimeSetBits(int L, int R) {
        bitset<32> num(L);
        string s = num.to_string();
        set<int> prime{2,3,5,7,11,13,17,19,23,29,31};
        int ct = num.count();
        
        int res = 0;
        while (L <= R)
        {
            if (prime.find(ct) != prime.end())
                ++res;
            int t = 1;
            for (int i = 31; i >= 0; --i)
            {
                char c = s[i] + t;
                if (c == '1')
                {
                    ++ct;
                    s[i] = '1';
                    break;
                }
                else
                {
                    --ct;
                    s[i] = '0';
                }
            }
            ++L;
        }
        
        return res;
    }