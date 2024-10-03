int numberOfPoints(vector<vector<int>>& nums) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return (a[0]<b[0]) || (a[0]==b[0] && a[1] < b[1]);
        };

        sort(nums.begin(), nums.end(), cmp);

        int len = nums.size();
        int s0 = nums[0][0], e0 = nums[0][1];
        int i = 1, ct = 0;

        while (i < len)
        {
            if(nums[i][0] <= e0)
                e0 = max(e0, nums[i][1]);
            else
            {
                ct += e0-s0+1;
                s0 = nums[i][0];
                e0 = nums[i][1];
            }
            ++i;
        }

        ct += e0-s0+1;

        return ct;
    }