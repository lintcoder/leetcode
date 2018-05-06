int totalHammingDistance(vector<int>& nums) {
	    int len = nums.size();
	    if (len < 2)
	    	return 0;

        vector<bitset<32>> bs(len, bitset<32>(0));
        for (int i = 0; i < len; ++i)
        	bs[i] = nums[i];

        int ct = 0;
        int flag[32][2] = {0};
        for (int i = 0; i < len; ++i)
        {
        	for (int j = 0; j < 32; ++j)
        	{
        		flag[j][bs[i][j]]++;
        	}
        }

        for (int i = 0; i < 32; ++i)
        	ct += flag[i][0] * flag[i][1];
        return ct;
    }