bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int len = arr.size();
        struct Elem
        {
            int pos;
            int length;
            Elem(int p = -1, int l = 0): pos(p), length(l){}
        };
        
        int n = pieces.size();
        map<int, Elem> mp;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int m = pieces[i].size();
            mp.insert(make_pair(pieces[i][0], Elem(i, m)));
            sum += m;
        }
        
        if (len != sum)
            return false;
        
        int i = 0;
        while (i < len)
        {
            auto iter = mp.find(arr[i]);
            if (iter == mp.end())
                return false;
            for (int k = 0; k < (iter->second).length; ++k)
            {
                if (arr[i] != pieces[(iter->second).pos][k])
                    return false;
                else
                    ++i;
            }
        }
        
        return true;
    }