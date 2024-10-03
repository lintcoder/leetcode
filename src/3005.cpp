int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            freq[nums[i]]++;
        }

        int maxfreq = 0;
        int ct = 0;
        for (int i = 0; i < 101; ++i)
        {
            if (freq[i] > maxfreq)
            {
                maxfreq = freq[i];
                ct = 1;
            }
            else if (maxfreq > 0 && freq[i] == maxfreq)
            {
                ++ct;
            }
        }

        return ct*maxfreq;
    }