int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int len = boxTypes.size();
        auto cmp = [&boxTypes](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1] || (a[1]==b[1] && a[0] > b[0]);
        };
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int i = truckSize;
        int j = 0;
        int sum = 0;
        while (i > 0 && j < len)
        {
            int n = boxTypes[j][0] <= i ? boxTypes[j][0] : i;
            sum += n*boxTypes[j][1];
            i -= n;
            ++j;
        }
        
        return sum;
    }