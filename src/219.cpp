bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<Elem> vec;
        for (int i = 0; i != sz; ++i)
            vec.push_back(Elem(nums[i], i));
        sort(vec.begin(), vec.end(), cmp);
        
        int i = 0, j = 0;
        while (i < sz)
        {
            int val = vec[i].val;
            j = i + 1;
            while (j < sz && vec[j].val == val)
            {
                if (vec[j].pos - vec[i].pos <= k)
                    return true;
                else
                {
                    i = j;
                    ++j;
                }
            }
            if (j == sz)
                return false;
            else
                i = j;
        }
        return false;
    }
    struct Elem{
        int val;
        int pos;
        Elem(int v, int p) : val(v), pos(p){}
    };
    static bool cmp(Elem a, Elem b)
    {
        return a.val < b.val || a.pos < b.pos; 
    }