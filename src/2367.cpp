int arithmeticTriplets(vector<int>& nums, int diff) {
        int len = nums.size();
        int ct = 0;
        for (int i = 0; i < len-2; ++i)
        {
            for (int j = i+1; j < len-1; ++j)
            {
                if(diff == nums[j]-nums[i])
                {
                    for (int k = j+1; k < len; ++k)
                    {
                        if (nums[k]-nums[j] == diff)
                        {
                            ++ct;
                            break;
                        }
                        else if(nums[k]-nums[j] > diff)
                            break;
                    }
                }
                else if(nums[j]-nums[i] > diff)
                    break;
            }
        }
        
        return ct;
    }