int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        if (len < 3)
        	return 0;

        sort(nums.begin(), nums.end());
        int ct = 0;
        for (int i = 0; i < len-2; ++i)
        {
            bool flag = true;
        	for (int j = i+1; j < len-1; ++j)
        	{
        		if (flag == false)
        			ct += len-1-j;
        		else
        		{
	        		auto p = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j]);
	        		ct += p-nums.begin()-j-1;
	        		if (p == nums.end())
	        			flag = false;
	        	}
        	}
        }

        return ct;
    }