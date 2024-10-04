int minElement(vector<int>& nums) {
        int minval = 100;
        for (int a: nums)
        {
            int tmp = 0;
            while (a > 0)
            {
                tmp += a%10;
                a /= 10;
            }
            if (tmp < minval)
                minval = tmp;
        }

        return minval;
    }