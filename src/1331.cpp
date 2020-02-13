vector<int> arrayRankTransform(vector<int>& arr) {
        int len = arr.size();
        if (len == 0)
            return {};
        if (len == 1)
            return {1};
        
        struct Elem
        {
            int val;
            int pos;
            int rank;
            Elem(int v = 0, int p = -1, int r = 1):val(v), pos(p), rank(r){}
        };
        
        vector<Elem> vec(len);
        for (int i = 0; i < len; ++i)
        {
            vec[i].val = arr[i];
            vec[i].pos = i;
        }
        
        auto cmp = [](const Elem& a, const Elem& b) {
            return a.val < b.val;
        };
        
        sort(vec.begin(), vec.end(), cmp);
        vector<int> res(len, 1);
        int rank = 1;
        for (int i = 1; i < len; ++i)
        {
            if (vec[i].val > vec[i-1].val)
            {
                ++rank;
            }
            vec[i].rank = rank;
        }
        for (int i = 0; i < len; ++i)
            res[vec[i].pos] = vec[i].rank;
        
        return res;
    }