int minOperations(vector<string>& logs) {
        int len = logs.size();
        int depth = 0;
        for (int i = 0; i < len; ++i)
        {
            if (logs[i] == "../")
            {
                if (depth > 0)
                    --depth;
            }
            else if (logs[i] == "./")
                ;
            else
                ++depth;
        }
        
        return depth;
    }