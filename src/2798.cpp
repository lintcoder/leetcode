int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = hours.size(), ct = 0;
        for (int i = 0; i < n; ++i)
        {
            if (hours[i] >= target)
                ++ct;
        }

        return ct;
    }