vector<int> countBits(int num) {
        int binarr[32] = {0};
        int ct = 0;
        vector<int> res(num+1, 0);
        
        for (int i = 0; i < num; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                if (binarr[j] == 0)
                {
                    ++ct;
                    res[i+1] = ct;
                    binarr[j] = 1;
                    break;
                }
                else
                {
                    binarr[j] = 0;
                    --ct;
                }
            }
        }
        
        return res;
    }