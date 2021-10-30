vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int arr[101][3];
        memset(arr, 0, 303*sizeof(int));
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len3 = nums3.size();
        for (int i = 0; i < 100; ++i)
        {
            if (i < len1)
            {
                if (arr[nums1[i]][0] == 0)
                    ++arr[nums1[i]][0];
            }
            if (i < len2)
            {
                if (arr[nums2[i]][1] == 0)
                    ++arr[nums2[i]][1];
            }
            if (i < len3)
            {
                if (arr[nums3[i]][2] == 0)
                    ++arr[nums3[i]][2];
            }
        }
        
        vector<int> res;
        for (int i = 0; i < 101; ++i)
        {
            if (arr[i][0] + arr[i][1] + arr[i][2] >= 2)
                res.push_back(i);
        }
        
        return res;
    }