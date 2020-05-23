vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int maxmum = candies[0];
        for (int i = 1; i < len; ++i)
        {
            if (candies[i] > maxmum)
                maxmum = candies[i];
        }
        
        vector<bool> res(len);
        for (int i = 0; i < len; ++i)
        {
            if (candies[i]+extraCandies >= maxmum)
                res[i] = true;
        }
        
        return res;
    }