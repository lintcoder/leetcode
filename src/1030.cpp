vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int total = R*C;
        vector<vector<int>> res(total, vector<int>(2, 0));
        struct Elem
        {
            int r;
            int c;
            int dist;
            Elem(int _r = 0, int _c = 0):r(_r),c(_c){}
        };
        
        vector<Elem> vec(total);
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                vec[i*C+j].r = i;
                vec[i*C+j].c = j;
                vec[i*C+j].dist = abs(i-r0) + abs(j-c0);
            }
        }
        
        auto cmp = [](const Elem& a, const Elem& b){
            return a.dist < b.dist;
        };
        sort(vec.begin(), vec.end(), cmp);
        
        for (int i = 0; i < total; ++i)
        {
            res[i][0] = vec[i].r;
            res[i][1] = vec[i].c;
        }
        
        return res;
    }