bool checkIfExist(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (arr[i]*2 == arr[j] || arr[i] == arr[j]*2)
                    return true;
            }
        }
        
        return false;
    }