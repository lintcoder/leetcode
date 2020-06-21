bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int len = target.size();
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < len; ++i)
        {
            if (target[i] != arr[i])
                return false;
        }
        
        return true;
    }