int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int n = nums1.size();
        return (sum2-sum1)/n;
    }