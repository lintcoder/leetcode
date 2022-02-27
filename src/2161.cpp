vector<int> pivotArray(vector<int>& nums, int pivot) {
        auto cmp = [&](int a, int b) {
            return (a < pivot && b == pivot) || (a < pivot && b > pivot) || (a == pivot && b > pivot);
        };
        
        stable_sort(nums.begin(), nums.end(), cmp);   
        return nums;
    }