char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int len = releaseTimes.size();
        int maxtime = releaseTimes[0];
        char c = keysPressed[0];
        for (int i = 1; i < len; ++i)
        {
            int duration = releaseTimes[i] - releaseTimes[i-1];
            if (duration > maxtime)
            {
                maxtime = duration;
                c = keysPressed[i];
            }
            else if (duration == maxtime)
            {
                if (keysPressed[i] > c)
                    c = keysPressed[i];
            }
        }
        
        return c;
    }