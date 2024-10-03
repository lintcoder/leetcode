vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int a = 0, b = 0;
        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else
            {
                while (i < n && nums1[i] == nums2[j])
                {
                    ++a;
                    ++i;
                }
                while (j < m && nums1[i-1] == nums2[j])
                {
                    ++b;
                    ++j;
                }
            }
        }

        return {a, b};
    }