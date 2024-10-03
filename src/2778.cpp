int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int squareSum = 0;
        int lim = sqrt(n);

        for (int i = 1; i < lim; ++i)
        {
            if (n%i == 0)
            {
                squareSum += nums[i-1]*nums[i-1] + nums[n/i-1]*nums[n/i-1];
            }
        }

        int tmp = n/lim;
        if (n%lim == 0)
        {
            squareSum += nums[lim-1]*nums[lim-1];
            if (tmp != lim)
                squareSum += nums[tmp-1]*nums[tmp-1];
        }

        return squareSum;
    }