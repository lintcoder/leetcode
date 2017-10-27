int distributeCandies(vector<int>& candies) {
        size_t sz = candies.size();
        if (sz == 0)
            return 0;
            
        sort(candies.begin(), candies.end());
        size_t kind = 1, i = 1;
        int num = candies[0];
        while (i < sz)
        {
            if (candies[i] != num)
            {
                num = candies[i];
                kind++;
            }
            ++i;
        }
        return kind <= sz/2 ? kind : sz/2;
    }