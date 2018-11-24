int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 0)
            return 0;
        vector<vector<int>> subsum(sz, vector<int>(sz, -1));
        return collectmoney(nums, 0, sz - 1, subsum);
    }
    
    int collectmoney(const vector<int>& money, int p, int q, vector<vector<int>>& subsum)
    {
       if(subsum[p][q] != -1)
           return subsum[p][q];
       if (p == q - 1)
       {
           subsum[p][q] = money[p] > money[q] ? money[p] : money[q]; 
       }
       else if (p == q)
       {
           subsum[p][q] = money[p];
       }
       else
       {
           int sum1 = money[p] + collectmoney(money, p + 2, q, subsum);
           int sum2 = collectmoney(money, p + 1, q, subsum);
           subsum[p][q] = sum1 > sum2 ? sum1 : sum2;
       }
       
       return subsum[p][q];
    }