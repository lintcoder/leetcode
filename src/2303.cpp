double calculateTax(vector<vector<int>>& brackets, int income) {
        int len = brackets.size();
        double taxes = 0;
        int last = 0;
        
        for (int i = 0; i < len; ++i)
        {
            int num = brackets[i][0]-last;
            double val = num < income ? num : income;
            taxes += val*brackets[i][1]/100;
            
            if (income <= num)
                break;
            income -= num;
            last = brackets[i][0];
        }
        
        return taxes;
    }