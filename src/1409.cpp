vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> arr(m);
        for (int i = 0; i < m; ++i)
            arr[i] = i+1;
        
        int len = queries.size();
        vector<int> res(len);
        for (int i = 0; i < len; ++i)
        {
            int j;
            for (j = m-1; j >= 0; --j)
            {
                if (arr[j] == queries[i])
                {
                    res[i] = j;
                    break;
                }
            }
            for (; j >= 1; --j)
                arr[j] = arr[j-1];
            arr[0] = queries[i];
        }
        
        return res;
    }