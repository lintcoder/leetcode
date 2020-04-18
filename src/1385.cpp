int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len1 = arr1.size(), len2 = arr2.size();
        int ct = 0;
        for (int i = 0; i < len1; ++i)
        {
            int j = 0;
            for (j = 0; j < len2; ++j)
                if (abs(arr1[i]-arr2[j]) <= d)
                    break;
            if (j == len2)
                ++ct;
        }
        
        return ct;
    }