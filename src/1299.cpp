vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        if (len == 1)
            return {-1};
        
        vector<int> res(len, -1);
        int maxnum = -1;
        int i = len-1;
        while (i > 0)
        {
            if (arr[i] > maxnum)
            {
                maxnum = arr[i];
            }
            res[i-1] = maxnum;
            --i;
        }
        
        return res;
    }
