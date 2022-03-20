vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int len = nums.size();
        vector<int> pos;
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] == key)
            {
                pos.push_back(i);
                ++ct;
            }
        }
        
        vector<int> res;
        int lh = -1, rh = -1;
        for (int i = 0; i < ct; ++i)
        {
            int l = pos[i]-k > 0 ? pos[i]-k : 0;
            int r = pos[i]+k < len ? pos[i]+k : len-1;
            lh = l >= rh+1 ? l : rh+1;
            rh = r;
            for (int j = lh; j <= rh; ++j)
                res.push_back(j);
            
            if (rh == len-1)
                break;
        }
        
        return res;
    }