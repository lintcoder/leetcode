int getKth(int lo, int hi, int k) {
        struct Elem
        {
            int val;
            int ct;
            Elem(int v = 0, int n = 0):val(v),ct(n){}
        };
        
        vector<Elem> res(hi-lo+1);
        for (int i = lo; i <= hi; ++i)
        {
            int t = i;
            int ct = 0;
            while (t != 1)
            {
                if (t%2 == 0)
                    t /= 2;
                else
                    t = t*3+1;
                ++ct;
            }
            
            res[i-lo].val = i;
            res[i-lo].ct = ct;
        }
        
        auto cmp = [](const Elem& a, const Elem& b) {
            return a.ct < b.ct || (a.ct == b.ct && a.val < b.val);
        };
        
        sort(res.begin(), res.end(), cmp);
        
        return res[k-1].val;
    }