public:
    NumArray(vector<int> nums) {
            int len = nums.size();
            arry.assign(len, 0);
            for (int i = 0; i < len; ++i)
                arry[i] = nums[i];
        }
    
    int sumRange(int i, int j) {
        int sum = arry[i];
        for (int m = i + 1; m <= j; ++m)
            sum += arry[m];
        return sum;
    }
private:
    vector<int> arry;