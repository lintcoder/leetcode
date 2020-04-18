int findLucky(vector<int>& arr) {
        int len = arr.size();
        if (len == 1)
            return arr[0] == 1 ? 1 : -1;
        sort(arr.begin(), arr.end());
        int i = len-1;
        while (i >= 0)
        {
            int tmp = arr[i];
            if (i-tmp+1 >= 0 && arr[i-tmp+1] == tmp)
            {
                if (i-tmp < 0 || arr[i-tmp] != tmp)
                    return tmp;
                else
                    i = i-tmp;
            }
            
            for (; i >= 0; --i)
                if (arr[i] != tmp)
                    break;
        }
        
        return -1;
    }