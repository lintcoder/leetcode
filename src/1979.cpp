int findGCD(vector<int>& nums) {
        int len = nums.size();
        int minval = nums[0], maxval = nums[0];
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] < minval)
                minval = nums[i];
            if (nums[i] > maxval)
                maxval = nums[i];
        }
        
        return gcd(minval, maxval);
    }
    
    int gcd(int a, int b)
    {
        if (a > b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        
        if (b%a == 0)
            return a;
        else
        {
            b %= a;
            return gcd(b, a);
        }
    }