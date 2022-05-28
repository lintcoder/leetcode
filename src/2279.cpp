int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int len = capacity.size();
        vector<int> lessvec(len, 0);
        
        for (int i = 0; i < len; ++i)
        {
            lessvec[i] = capacity[i]-rocks[i];
        }
        
        sort(lessvec.begin(), lessvec.end());
        
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (lessvec[i] == 0)
                ++ct;
            else
            {
                if (additionalRocks >= lessvec[i])
                {
                    additionalRocks -= lessvec[i];
                    ++ct;
                }
            }
        }
        
        return ct;
    }