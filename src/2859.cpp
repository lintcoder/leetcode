int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        int i = pow(2, k)-1;
        for (; i < len; ++i)
        {
            int tmp = i;
            int ct = 0;
            while (tmp != 0)
            {
                if((tmp & 0x1) != 0)
                    ++ct;
                tmp >>= 1;
            }
            if(ct == k)
                sum += nums[i];
        }

        return sum;
    }