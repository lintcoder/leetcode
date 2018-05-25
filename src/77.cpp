vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < k)
        	return res;
        for (int i = 1; i <= n-k+1; ++i)
        {
        	vector<int> vec(k, 0);
        	vec[0] = i;
        	docombine(n, i+1, k, 1, vec, res);
        }

        return res;
    }

    void docombine(int n, int index, int k, int count, vector<int>& vec, vector<vector<int>>& res)
    {
        if (count == k)
            res.push_back(vec);
        else
        {
            for (int i = index; i <= n-k+1+count; ++i)
            {
                vector<int> tmp(vec);
                tmp[count] = i;
                docombine(n, i+1, k, count+1, tmp, res);
            }
        }
    }