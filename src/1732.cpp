int largestAltitude(vector<int>& gain) {
        int high = 0;
        int highest = 0;
        int len = gain.size();
        for (int i = 0; i < len; ++i)
        {
            high += gain[i];
            if (high > highest)
                highest = high;
        }
        
        return highest;
    }