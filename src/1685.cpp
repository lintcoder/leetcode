    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> accusum(len, 0);
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
            accusum[i] = sum;
        }
        
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i)
        {
            res[i] = accusum[len-1]-accusum[i]-(len-1-i)*nums[i]+(i+1)*nums[i]-accusum[i];
        }
        
        return res;
    }