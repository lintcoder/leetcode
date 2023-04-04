long long findTheArrayConcVal(vector<int>& nums) {
        int len = nums.size();
        int lim = len/2;
        long long concatsum = 0;

        const long long coeff[] = {10, 100, 1000, 10000, 100000};

        for (int i = 0; i < lim; ++i)
        {
            int n = log10(nums[len-1-i]);
            concatsum += nums[i]*coeff[n] + nums[len-1-i];
        }

        if (len%2 != 0)
            concatsum += nums[lim];

        return concatsum;
    }