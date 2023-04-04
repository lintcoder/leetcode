vector<int> evenOddBit(int n) {
        vector<int> res(2, 0);
        int i = 0;
        
        while (n != 0)
        {
            res[i] += n & 0x1;
            i = 1-i;
            n >>= 1;
        }

        return res;
    }