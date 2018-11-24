vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        struct Elem
        {
            int val;
            int pos;
            Elem(int v, int p):val(v), pos(p){}
        };
        auto cmp = [=](const Elem& a, const Elem& b) {
            return a.val < b.val;
        };
        auto binsearch = [=](const vector<Elem>& vec, int p, int q, int v) {
            while (p <= q)
            {
                int mid = (p + q) / 2;
                if (vec[mid].val == v)
                    return vec[mid].pos;
                else if (vec[mid].val < v)
                    p = mid + 1;
                else
                    q = mid - 1;
            }
            return -1;
        };
        
        vector<Elem> vec;
        for (int i = 0; i < len; ++i)
            vec.push_back(Elem(nums[i], i));
            
        vector<int> res;
        sort(vec.begin(), vec.end(), cmp);
        int pos = 0;
        for (int i = 0; i < len; ++i)
        {
            if ((pos = binsearch(vec, i+1, len - 1, target - vec[i].val)) != -1)
            {
                res.push_back(vec[i].pos);
                res.push_back(pos);
                break;
            }
        }
        return res;
    }