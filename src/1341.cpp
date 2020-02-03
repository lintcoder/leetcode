vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        if (row == 1)
            return {0};
        int col = mat[0].size();
        
        struct Elem
        {
            int num;
            int index;
            Elem(int n = 0, int id = -1):num(n),index(id){}
        };
        auto cmp = [](const Elem& a, const Elem& b){
            return a.num < b.num || (a.num == b.num && a.index < b.index);
        };
        
        vector<Elem> vec(row, Elem());
        for (int i = 0; i < row; ++i)
        {
            vec[i].num = mat[i].rend() - upper_bound(mat[i].rbegin(), mat[i].rend(), 0);
            vec[i].index = i;
        }
        
        sort(vec.begin(), vec.end(), cmp);
        vector<int> res(k, -1);
        for (int i = 0; i < k; ++i)
            res[i] = vec[i].index;
        
        return res;
    }