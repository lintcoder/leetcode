bool threeConsecutiveOdds(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len-2; ++i)
        {
            if (arr[i]%2 == 1 && arr[i+1]%2 == 1 && arr[i+2]%2 == 1)
            {
                return true;
            }
        }
        
        return false;
    }