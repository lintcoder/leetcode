vector<long long> sumOfThree(long long num) {
        if (num%3 != 0)
            return {};
        vector<long long> res(3, 0);
        res[0] = num/3-1;
        res[1] = num/3;
        res[2] = num/3+1;
        
        return res;
    }