bool isThree(int n) {
        int num[25] = {2,3,5,7,11,13,17,19,23,29,31,
                    37,41,43,47,53,59,61,67,71,73,
                    79,83,89,97};
        for (int i = 0; i < 25; ++i)
        {
            if (num[i]*num[i] == n)
                return true;
        }
        
        return false;
    }