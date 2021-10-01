int finalValueAfterOperations(vector<string>& operations) {
        int len = operations.size();
        int result = 0;
        for (int i = 0; i < len; ++i)
        {
            if (operations[i].find('+') != string::npos)
                ++result;
            else
                --result;
        }
        
        return result;
    }