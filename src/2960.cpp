int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int m = 0;

        for (int i = 0; i < n; ++i)
        {
            if (batteryPercentages[i] > m)
            {
                ++m;
            }
        }

        return m;
    }