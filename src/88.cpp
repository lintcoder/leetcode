void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* arr = new int[m + n];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                arr[k++] = nums1[i];
                i++;
            }
            else
            {
                arr[k++] = nums2[j];
                j++;
            }
        }
        while (i < m)
            arr[k++] = nums1[i++];
        while (j < n)
            arr[k++] = nums2[j++];
        nums1.assign(arr, arr + m + n);
        delete[] arr;
    }