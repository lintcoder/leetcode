vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(2*len);
        res.assign(nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        
        return res;
    }