int findNonMinOrMax(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
            return -1;
        
        int minval = 101, maxval = 0;
        int ct = 0;
        int res = 0;

        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < minval)
            {
                if (minval != 101)
                {
                    ++ct;
                    if (ct == 2)
                    {
                        res = minval;
                        break;
                    }
                }
                minval = nums[i];
            }
            if (nums[i] > maxval)
            {
                if (maxval != 0)
                {
                    ++ct;
                    if (ct == 2)
                    {
                        res = maxval;
                        break;
                    }
                }
                maxval = nums[i];
            }

            if (nums[i] != minval && nums[i] != maxval)
            {
                res = nums[i];
                break;
            }
        }

        return res;
    }