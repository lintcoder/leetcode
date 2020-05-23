int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int len = startTime.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                ++ct;
        }
        
        return ct;
    }