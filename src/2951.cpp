vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        int len = mountain.size();
        for (int i = 1; i < len-1; ++i)
        {
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1])
                res.push_back(i);
        }

        return res;
    }