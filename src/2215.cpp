vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int arr1[2001] = {0};
        int arr2[2001] = {0};
        int len1 = nums1.size(), len2 = nums2.size();
        for (int i = 0; i < len1; ++i)
            arr1[nums1[i]+1000] = 1;
        for (int i = 0; i < len2; ++i)
            arr2[nums2[i]+1000] = 1;
        
        vector<vector<int>> res(2, vector<int>());
        for (int i = 0; i < 2001; ++i)
        {
            if (arr1[i] != 0 && arr2[i] == 0)
                res[0].push_back(i-1000);
            if (arr1[i] == 0 && arr2[i] != 0)
                res[1].push_back(i-1000);
        }
        
        return res;
    }