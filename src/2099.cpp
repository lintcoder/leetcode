vector<int> maxSubsequence(vector<int>& nums, int k) {
        struct Elem
        {
            int val;
            int pos;
            Elem(int v = 0, int p = 0):val(v),pos(p){}
        };
        
        int len = nums.size();
        vector<Elem> vec(len, Elem());
        for (int i = 0; i < len; ++i)
        {
            vec[i].val = nums[i];
            vec[i].pos = i;
        }
        
        auto cmp = [](const Elem& a, const Elem& b) {
            return (a.val < b.val) || (a.val == b.val && a.pos < b.pos);
        };
        auto cmp2 = [](const Elem& a, const Elem& b) {
            return a.pos < b.pos;
        };
        
        sort(vec.begin(), vec.end(), cmp);
        sort(vec.begin()+len-k, vec.end(), cmp2);
        
        vector<int> res(k, 0);
        for (int i = 0; i < k; ++i)
            res[i] = vec[i+len-k].val;
        
        return res;   
    }