int maxDistance(vector<int>& colors) {
        int maxdist = 0;
        int len = colors.size();
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (colors[i] != colors[j])
                {
                    maxdist = j-i > maxdist ? j-i : maxdist;
                }
            }
        }
        
        return maxdist;
    }