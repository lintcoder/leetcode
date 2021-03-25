vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> res(len, 0);
        
        for (int i = 0; i < len; ++i)
        {
            int ct = 0;
            for (int j = 0; j < len; ++j)
            {
                if (boxes[j] == '1')
                    ct += abs(j-i);
            }
            res[i] = ct;
        }
        
        return res;
    }