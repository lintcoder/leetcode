int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] < nums2[j])
                ++i;
            else
                ++j;
        }

        while (i < len1 && nums1[i] < nums2[len2-1])
            ++i;
        while (j < len2 && nums2[j] < nums1[len1-1])
            ++j;
        
        if (i == len1 || nums1[i] > nums2[len2-1])
            return -1;
        else if (j == len2 || nums2[j] > nums1[len1-1])
            return -1;
        else if (i < len1)
            return nums2[len2-1];
        else
            return nums1[len1-1];
    }