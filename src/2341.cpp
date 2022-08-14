vector<int> numberOfPairs(vector<int>& nums) {
        int arr[101] = {0};
        int len = nums.size();
        
        for (int i = 0; i < len; ++i)
            arr[nums[i]]++;
        
        vector<int> res(2, 0);
        for (int i = 0; i < 101; ++i)
        {
            res[0] += arr[i]/2;
            res[1] += arr[i]%2;
        }
        
        return res;
    }