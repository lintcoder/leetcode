double average(vector<int>& salary) {
        int len = salary.size();
        int minval = 1e6, maxval = 0;
        double sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += salary[i];
            if (salary[i] < minval)
                minval = salary[i];
            if (salary[i] > maxval)
                maxval = salary[i];
        }
        
        sum -= (minval+maxval);
        
        return sum/(len-2);
    }