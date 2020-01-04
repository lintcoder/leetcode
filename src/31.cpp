void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
        	return;
        if (len == 2)
        	swap(nums[0], nums[1]);
        else
        {
        	int i = len - 1;
        	while (i > 0 && nums[i-1] >= nums[i])
        		--i;
        	if (i == 0)
        		reverse(nums.begin(), nums.end());
        	else
        	{
        		int j = len - 1;
        		while (j >= i && nums[j] <= nums[i-1])
        			--j;
        		swap(nums[i-1], nums[j]);
        		reverse(nums.begin()+i, nums.end());
        	}
        }
    }