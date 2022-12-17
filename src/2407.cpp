int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            st.insert(nums[i]);
            int val = 0;
            int tmp = nums[i];
            while (tmp != 0)
            {
                val = val*10 + tmp%10;
                tmp /= 10;
            }
            st.insert(val);
        }

        return st.size();
    }