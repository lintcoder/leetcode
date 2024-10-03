vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        int len = height.size();

        for (int i = 1; i < len; ++i)
        {
            if (height[i-1] > threshold)
                res.push_back(i);
        }

        return res;
    }