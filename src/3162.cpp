int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ct = 0;
        for (int a: nums1)
        {
            for (int b: nums2)
            {
                if (a%(b*k) == 0)
                    ++ct;
            }
        }

        return ct;
    }