vector<int> decode(vector<int>& encoded, int first) {
        int len = encoded.size();
        vector<int> res(len+1, 0);
        res[0] = first;
        for (int i = 0; i < len; ++i)
        {
            res[i+1] = encoded[i]^res[i];
        }
        
        return res;
    }