vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i)
        {
            if (isselfdivide(i))
                res.push_back(i);
        }
        
        return res;
    }
    
    bool isselfdivide(int num)
    {
        int n = num;
        while (n != 0)
        {
            int r = n % 10;
            if (r == 0 || num % r != 0)
                return false;
            n /= 10;
        }
        
        return true;
    }