bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        if (len == 1)
            return arr[0] == 0;
        vector<int> flag(len, 0);
        
        return search(arr, start, len, flag);
    }
    
    bool search(vector<int>& arr, int pos, int len, vector<int>& flag)
    {
        if (pos < 0 || pos >= len)
            return false;
        if (arr[pos] == 0)
            return true;
        if (flag[pos] == 1)
            return false;
        
        flag[pos] = 1;
        int p1 = pos + arr[pos];
        int p2 = pos - arr[pos];
        return search(arr, p1, len, flag) || search(arr, p2, len, flag);
    }